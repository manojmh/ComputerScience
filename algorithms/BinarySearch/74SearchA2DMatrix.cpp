/**
https://leetcode.com/problems/search-a-2d-matrix/
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
**/
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& A, int key) {
    int n = A.size();
    if(n == 1 && n == 1) {
      if(A[0][0] == key)
        return true;
      return false;
    }
    int i=0, j=A[0].size()-1;
    while(i < n && j >= 0) {
      if(key == A[i][j])
        return true;
      else if(A[i][j] > key)
        j--;
      else
        i++;
    }
    return false;
  }
};
