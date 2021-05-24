/**
https://www.interviewbit.com/problems/subset/
Given a set of distinct integers, S, return all possible subsets.
Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :
If S = [1,2,3], a solution is:
[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]
**/
void subset(vector<int> &in, vector<int> tempOut, vector<vector<int>> &out, int i) {
  if(i==in.size()) {
    out.push_back(tempOut);
    return;
  }
  //Not included in output
  subset(in, tempOut, out, i+1);
  //included in output
  tempOut.push_back(in[i]);
  subset(in, tempOut, out, i+1);
}
vector<vector<int>> Solution::subsets(vector<int> &A) {
  vector<int> t;
  vector<vector<int>> out;
  sort(A.begin(), A.end());
  subset(A, t, out, 0);
  sort(out.begin(), out.end());
  return out;
}
