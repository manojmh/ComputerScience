/** Microsoft, JP Morgan, Amazon, Flipkart, Adobe
Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.
Example:
Given the following matrix:
[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return
[1, 2, 3, 6, 9, 8, 7, 4, 5]
**/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
  vector<int> res;
  int row = 0, col = 0;
  int maxRow = A.size(), maxCol = A[0].size();
  //If there is only one row
  if(maxRow == 1) {
    for(int i=col; i<maxCol; i++)
      res.push_back(A[0][i]);
    return res;
  }
  //If there is only one col
  if(maxCol == 1) {
    for(int i=row; i<maxRow; i++)
      res.push_back(A[i][0]);
    return res;
  }

  while(row < maxRow && col < maxCol) {
    for(int i = col; i<maxCol; i++)
      res.push_back(A[row][i]);
    row++;

    for(int i = row; i < maxRow ; i++)
      res.push_back(A[i][maxCol-1]);
    maxCol--;

    if(row < maxRow) {
      for(int i=maxCol-1; i>=col; i--)
        res.push_back(A[maxRow-1][i]);
      maxRow--;
    }

    if(col < maxCol) {
      for(int i=maxRow-1; i>=row; i--)
        res.push_back(A[i][col]);
      col++;
    }
  }
  return res;
}
