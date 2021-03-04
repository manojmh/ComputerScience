/** Booking.com
Given an array of integers A and multiple values in B which represents the indices of the array A around which left rotation of the array A needs to be performed.
Find the rotated array for each value and return the result in the from of a matrix where i'th row represents the rotated array for the i'th value in B.
Problem Constraints
1 <= length of both arrays <= 2000
-109 <= A[i] <= 109
0 <= B[i] <= 2000
Input Format
The first argument given is the integer array A.
The second argument given is the integer array B.
Output Format
Return the resultant matrix.
Example Input
Input 1: A = [1, 2, 3, 4, 5] B = [2, 3]
Input 2: A = [5, 17, 100, 11] B = [1]
Example Output
Output 1: [ [3, 4, 5, 1, 2] [4, 5, 1, 2, 3] ]
Output 2: [ [17, 100, 11, 5] ]
**/
vector<vector<int> > Solution::solve(vector<int> &A, vector<int> &B) {
  vector<vector<int>> res;
  int j = 0;
  for(auto b : B) {
    vector<int> temp;
    for(int i=0; i<A.size(); i++) {
      temp.push_back(A[(i+b)%A.size()]);
    }
    res.push_back(temp);
    j++;
  }
  return res;
}
