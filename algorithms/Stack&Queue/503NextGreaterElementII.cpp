/**
https://leetcode.com/problems/next-greater-element-ii/
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]),
return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array,
which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
Example 1:
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
Constraints:
1 <= nums.length <= 104
-109 <= nums[i] <= 109
**/
class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> s;
    vector<int> v;
    nums.insert(nums.end(), nums.begin(), nums.end());
    for(int i=nums.size()-1; i>=0 ; i--) {
      if(s.empty())
        v.push_back(-1);
      else if(s.top() > nums[i])
        v.push_back(s.top());
      else {
        while(!s.empty() && s.top() <= nums[i])
          s.pop();
        if(s.empty())
          v.push_back(-1);
        else
          v.push_back(s.top());
      }
      s.push(nums[i]);
    }
    reverse(v.begin(), v.end());
    v.resize(v.size()/2);
    return v;
  }
};
