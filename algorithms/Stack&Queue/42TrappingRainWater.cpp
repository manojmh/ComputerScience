/**
https://leetcode.com/problems/trapping-rain-water/
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.
Example 1: Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.
Example 2: Input: height = [4,2,0,3,2,5]
Output: 9
Constraints:
n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105
**/
class Solution {
public:
  int trap(vector<int>& A) {
    if(A.size() == 0) return 0;
    vector<int> maxLeft(A.size(), 0);
    vector<int> maxRight(A.size(), 0);

    maxLeft[0] = A[0];
    for(int i=1; i<A.size(); i++)
      maxLeft[i] = max(maxLeft[i-1], A[i]);

    maxRight[A.size()-1] = A[A.size()-1];
    for(int i=A.size()-2; i>=0; i--)
      maxRight[i] = max(maxRight[i+1], A[i]);

    int ans = 0;
    for(int i=0; i<A.size(); i++)
        ans += min(maxLeft[i], maxRight[i]) - A[i];

    return ans;
  }
};
