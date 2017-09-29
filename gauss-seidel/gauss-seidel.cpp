// Gauss-Seidel Iterative Method
// to determine solution of linear equation system

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Global Variable Declaration
float my_matrix[20][20];

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

  // Main Program


}

int main () {

  // Variable Declaration
  int n;

  // Main Program
  cout << "-------------- Gauss-Seidell Iterative Method --------------" <<endl;
  cout << endl;
  cout << "Input the dimension of the matrix : ";
  cin >> n;

  return 0
}
