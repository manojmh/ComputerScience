/**
https://www.interviewbit.com/problems/combination-sum/
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
The same repeated number may be chosen from C unlimited number of times.
Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example,
Given candidate set 2,3,6,7 and target 7,
A solution set is:
[2, 2, 3]
[7]
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 
**/
void combine(vector<int> &tempOut,
           set<vector<int>> &out,
           vector<int> &in,
           int target,
           int curSum,
           int i) {
  if(curSum == target) {
    sort(tempOut.begin(), tempOut.end());
    out.insert(tempOut);
    return;
  }
  if(curSum > target)
    return;
  for(int j=i; j<in.size(); j++) {
    tempOut.push_back(in[j]);
    combine(tempOut, out, in, target, curSum+in[j], j);
    tempOut.pop_back();
  }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
  set<vector<int>> out;
  vector<int> tempOut;
  int curSum = 0;
  sort(A.begin(), A.end());
  combine(tempOut, out, A, B, curSum, 0);
  return vector<vector<int>>(out.begin(), out.end());
}
