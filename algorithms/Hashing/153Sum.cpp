/**
https://leetcode.com/problems/3sum/
Given an integer array nums, return all the triplets
[nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:
Input: nums = []
Output: []
Example 3:
Input: nums = [0]
Output: []
Constraints:
0 <= nums.length <= 3000
-105 <= nums[i] <= 105
**/
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if(nums.size() <3) return vector<vector<int>>();
    sort(nums.begin(), nums.end());
    set<vector<int>> rs;
    for(int i=0; i<nums.size()-2; i++) {
      int j = i+1;
      int k = nums.size()-1;
      while (j < k) {
        int sum = nums[i]+nums[j]+nums[k];
        if(sum == 0) {
          vector<int> temp(3, 0);
          temp[0] = nums[i];
          temp[1] = nums[j];
          temp[2] = nums[k];
          rs.insert(temp);
          j++;
          k--;
        }
        else if(sum < 0)
          j++;
        else
          k--;
      }
    }
    vector<vector<int>> res(rs.begin(), rs.end());
    return res;
  }
};
