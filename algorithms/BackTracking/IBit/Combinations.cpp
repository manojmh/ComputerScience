/**
https://www.interviewbit.com/problems/combinations/
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.
Make sure the combinations are sorted.
To elaborate,
Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :
If n = 4 and k = 2, a solution is:
[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 
**/
void comb(int A, int B, vector<vector<int>>&ans, vector<int> &res, int i) {
  if(res.size()==B) {
    ans.push_back(res);
    return;
  }
  for(int j=i;j<=A;j++) {
    res.push_back(j);
    comb(A,B,ans,res,j+1);
    res.pop_back();
  }
}
vector<vector<int>> Solution::combine(int A, int B) {
  vector<int> arr;
  vector<int> res;
  vector<vector<int>> ans;
  comb(A,B,ans,res,1);
  return ans;
}
