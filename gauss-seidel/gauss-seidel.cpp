// Gauss-Seidel Iterative Method
// to determine solution of linear equation system

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Global Variable Declaration
int my_matrix[20][20];

// Function Declaration
void matrix_analysis (int size);
void strict_diag_dominant (int size);

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
    for (j = 0; j < size; j++) {
      matrix >> my_matrix[i][j];
    }
  }
  // ---------------------- END OF MATRIX INPUT PROCESS ----------------------

  // Main Program

  // ---------------------- END OF MAIN PROGRAM ----------------------

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
    if (aii > sum_entries) {
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

int main () {

  // Variable Declaration

  // Main Program

  return 0;
}
