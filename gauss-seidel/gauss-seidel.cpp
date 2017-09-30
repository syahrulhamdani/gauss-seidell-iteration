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

// Function Declaration
void matrix_analysis (int size);
void strict_diag_dominant (int size);
void gauss_seidell (int max_iter, int err, float val_init[]);

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

  // Main Program

  // ---------------------- END OF MAIN PROGRAM ----------------------

}

void strict_diag_dominant (int size) {

  // Local Variable Declaration

  // Main Program


}

void gauss_seidell (int max_iter, int err, float val_init[]) {

  // Local Variable Declaration
  int i, j, k;

  // Main Program


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
  gauss_seidell(iter, tol, x_init);

  return 0;
}
