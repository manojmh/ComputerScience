/**
Transpose of a matrix is obtained by changing rows to columns and columns to rows.
In other words, transpose of A[][] is obtained by changing A[i][j] to A[j][i].

**/

#include <iostream>
using namespace std;

int A[100][100];
int B[100][100];
int m, n;

void transposeInPlace() {
  for(int i = 0; i < m; ++i)
    for(int j = i+1; j < n; ++j)
      swap(A[i][j], A[j][i]);
}

void transpose() 
{
  int i, j; 
  for (i = 0; i < m; i++) 
      for (j = 0; j < n; j++) 
          B[i][j] = A[j][i]; 
}

int main() {
  cout << "\nEnter mXn : ";
  cin >> m >> n;
  cout << "\nEnter elements : \n";
  for(int i=0; i<m; ++i)
    for(int j=0; j<n; ++j)
      cin >> A[i][j];
  cout << endl;

  transposeInPlace();
  for(int i=0; i<m; ++i, cout << "\n")
    for(int j=0; j<n; ++j)
      cout << A[i][j] << " ";
  cout << endl;

  transpose();
  for(int i=0; i<m; ++i, cout << "\n")
    for(int j=0; j<n; ++j)
      cout << B[i][j] << " ";
  cout << endl;
  return 0;
}
