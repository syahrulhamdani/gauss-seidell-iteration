// Gauss-Seidel Iterative Method
// to determine solution of linear equation system

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

// Global Variable Declaration
int my_matrix[20][20];
int vector_b[20];
double eqsys[1000][20];

// Function Declaration
void matrix_analysis (int size);
void strict_diag_dominant (int size);
void gauss_seidell (int max_iter, int size, int err, float val_init[]);
double norm_infinity (double val[], int size);

void matrix_analysis (int size) {

  // Local Variable Declaration
  ifstream matrix;
  int i, j;

  // Input matrix from external .txt files
  matrix.open("matrix-input.txt");
  if (!matrix) {
    cout << "Warning! Please check your file name or the directory" << endl;
  }

  for (i = 0; i < size; i++) {
    for (j = 0; j < size+1; j++) {
      if (j != size) {
        matrix >> my_matrix[i][j];
      }
      else {
        matrix >> vector_b[i];
      }
    }
  }
  // ---------------------- END OF MATRIX INPUT PROCESS ----------------------

  // Display the matrix A of equation 'Ax = b'
  cout << endl << "# Matrix A : " << endl;
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      cout << right << setw(8) << my_matrix[i][j];
    }
    cout << endl;
  }

  // Display the vector b of equation 'Ax = b'
  cout << endl << "# Vector b : " << endl;
  for (i = 0; i < size; i++) {
    cout << right << setw(5) << vector_b[i] << endl;
  }

  // Call strict_diag_dominant function
  strict_diag_dominant(size);

}

void strict_diag_dominant (int size) {

  // Local Variable Declaration
  int new_matrix[20][20], sum_entries, aii;
  int i, j, is_sdd;

  // Main Program
  is_sdd = 0;
  for (i = 0; i < size; i++) {

    aii = abs(my_matrix[i][i]);
    sum_entries = 0;
    for (j = 0; j < size; j++) {
      sum_entries += abs(my_matrix[i][j]);    // Sum of all entries in row 'i'
    }
    // Check if 2*|aii| > sum of all entry in row 'i', then the row fulfill sdd
    if (2*aii > sum_entries) {
      is_sdd += 1;
    } else {
      is_sdd += 0;
    }
  }
  // Check whether all rows is fulfill sdd
  if (is_sdd == size) {
    cout << "Your matrix is strict diagonally dominant matrix and convergent";
  } else {
    cout << "Warning! your matrix isn't strict diagonally dominant matrix";
    cout << "and there's no guarantee to be convergent";
  }

}

double norm_infinity (double val[], int size) {

  // Local Variable Declaration
  int i, index;
  double max_val;

  // Main Program
  max_val = abs(val[0]);
  index = 0;
  for (i = 0; i < size; i++) {
    if ((abs(val[i]) > max_val) and (index != i)) {
      max_val = abs(val[i]);
      index = i;
      i = 0;
    }
  }

  return max_val;

}

void gauss_seidell (int max_iter, int size, int err, float val_init[]) {

  // Local Variable Declaration
  int i, j, k;
  double differ[20], denom[20], num, den, tol;

  // Main Program
  k = 1;
  tol = 1;    // Assign initial tolerance to zero

  // Assign eqsys array to be equals val_init (initial value)
  for (i = 0; i < size; i++) {
    eqsys[0][i] = val_init[i];
  }
  // Iteration process
  while ( (k <= max_iter) or (tol > err)) {

    for (i = 0; i < size; i++) {
      eqsys[k][i] = 0;    // Assign eqsys 'i' at iteration 'k' to zero
      for (j = 0; j < size; j++) {
        if (j < i) {    // xi = xi + sum(aij*xj), value of xj at iteration 'k'
          eqsys[k][i] += my_matrix[i][j] * eqsys[k][j];
        } else if (j > 1) {    // xi = xi + sum(aij*xj), value of xj at iteration 'k-1'
          eqsys[k][i] += my_matrix[i][j] * eqsys[k-1][j];
        }
      }
      eqsys[k][i] -= vector_b[i];    // subtract eqsys by vetcor_b
      eqsys[k][i] *= (-1/my_matrix[i][i]);    // multiply eqsys by -(1/aii)
    }

    k++;
    // Determine deviation for each entry in eqsys between current and previous iteration
    for (i = 0; i < size; i++) {
      differ[i] = eqsys[k][i] - eqsys[k-1][i];
      denom[i] = eqsys[k][i];
    }
    // Call function norm_infinity to determine norm of numerator and denominator
    num = norm_infinity(differ, size);
    den = norm_infinity(denom, size);
    // Calculate the current tolerance
    tol = num/den;
  }

}

int main () {

  // Variable Declaration
  int n, i, iter;
  float tol, x_init[20];

  // Main Program
  cout << "-------------- Gauss-Seidell Iterative Method --------------" <<endl;
  cout << endl;
  cout << "Input the dimension of the matrix : ";
  cin >> n;
  cout << "Input maximum iteration : ";
  cin >> iter;
  cout << "Input maximum tolerance of error : ";
  cin >> tol;
  cout << "Input the initial value of x :" << endl;
  for (i = 0; i < n; i++) {
    cout << "# value of x[" << i+1 << "] : ";
    cin >> x_init[i];
  }

  // Call function matrix_analysis
  matrix_analysis(n);

  // Call function gauss_seidell
  gauss_seidell(iter, n, tol, x_init);

  return 0;
}
