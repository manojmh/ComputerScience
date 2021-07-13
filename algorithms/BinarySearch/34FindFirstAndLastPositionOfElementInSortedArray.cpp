/**
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
**/
class Solution {
public:
  int bsearchFirst(vector<int> &A, int low, int high, int key) {
    int mid = -1;
    int res = -1;
    while(low<=high) {
      mid = low+(high-low)/2;
      if(key == A[mid]) {
        res = mid;
        high = mid-1;
      }
      else if(key < A[mid])
        high = mid-1;
      else
        low = mid+1;
    }
    return res;
  }
  int bsearchLast(vector<int> &A, int low, int high, int key) {
    int mid = -1;
    int res = -1;
    while(low<=high) {
      mid = low+(high-low)/2;
      if(key == A[mid]) {
        res = mid;
        low = mid+1;
      }
      else if(key < A[mid])
        high = mid-1;
      else
        low = mid+1;
    }
    return res;
  }
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans(2, -1);
    if(nums.size()==0)
      return ans;
    if(nums.size() == 1) {
      if(nums[0]==target) {
        ans[0] = 0;
        ans[1] = 0;
      }
      return ans;
    }
    ans[0] = bsearchFirst(nums, 0, nums.size()-1, target);
    ans[1] = bsearchLast(nums, 0, nums.size()-1, target);
    return ans;
  }
};
