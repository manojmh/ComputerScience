/** Oracle Amazon
Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.
Input Format:
The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
Output Format:
Return a 2-d matrix that satisfies the given conditions.
Constraints:
1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:
Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]
Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]
Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]
Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]
**/
class Solution {
public:
  void setZeroes(vector<vector<int> > &matrix) {
    int rownum = matrix.size();
    if (rownum == 0)  return;
    int colnum = matrix[0].size();
    if (colnum == 0)  return;

    bool hasZeroFirstRow = false, hasZeroFirstColumn = false;

    // Does first row have zero?
    for (int j = 0; j < colnum; ++j) {
      if (matrix[0][j] == 0) {
        hasZeroFirstRow = true;
        break;
      }
    }

    // Does first column have zero?
    for (int i = 0; i < rownum; ++i) {
      if (matrix[i][0] == 0) {
        hasZeroFirstColumn = true;
        break;
      }
    }

    // find zeroes and store the info in first row and column
    for (int i = 1; i < rownum; ++i) {
      for (int j = 1; j < colnum; ++j) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
     }

    // set zeroes except the first row and column
    for (int i = 1; i < rownum; ++i) {
      for (int j = 1; j < colnum; ++j) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0)  matrix[i][j] = 0;
      }
     }

    // set zeroes for first row and column if needed
    if (hasZeroFirstRow) {
      for (int j = 0; j < colnum; ++j) {
        matrix[0][j] = 0;
      }
    }
    if (hasZeroFirstColumn) {
      for (int i = 0; i < rownum; ++i) {
        matrix[i][0] = 0;
      }
    }
  }
};
