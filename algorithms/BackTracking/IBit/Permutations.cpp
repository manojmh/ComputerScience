/**
https://www.interviewbit.com/problems/permutations/
Given a collection of numbers, return all possible permutations.
Example:
[1,2,3] will have the following permutations:
[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
NOTE
No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.
Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 
**/
void permute1(vector<int> A, vector<vector<int>> &out, int start, int end) {
  if(start == end) {
    out.push_back(A);
    return;
  }
  for(int i=start; i<=end; i++) {
    swap(A[i], A[start]);
    permute1(A, out, start+1, end);
    swap(A[i], A[start]);
  }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
  vector<vector<int>> out;
  if(A.size() == 0) return out;
  int start = 0;
  int end = A.size()-1;
  permute1(A, out, start, end);
  return out;
}
