/**
https://leetcode.com/problems/subsets-ii/
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:
Input: nums = [0]
Output: [[],[0]]
**/
class Solution {
public:
  void subset(vector<int> &in, vector<int> tempOut, set<vector<int>> &s, int i) {
    if(i==in.size()) {
      s.insert(tempOut);
      return;
    }
    subset(in, tempOut, s, i+1);
    tempOut.push_back(in[i]);
    subset(in, tempOut, s, i+1);
  }
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>> rs;
    vector<int> tempOut;
    sort(nums.begin(), nums.end());
    subset(nums, tempOut, rs, 0);
    vector<vector<int>> res(rs.begin(), rs.end());
    return res;
  }
};
