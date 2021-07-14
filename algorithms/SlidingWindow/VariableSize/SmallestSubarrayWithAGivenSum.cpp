/**
https://www.educative.io/courses/grokking-the-coding-interview/7XMlMEQPnnQ
Given an array of positive numbers and a positive number ‘S,’
find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’.
Return 0 if no such subarray exists.
Example 1:
Input: [2, 1, 5, 2, 3, 2], S=7 
Output: 2
Explanation: The smallest subarray with a sum greater than or equal to '7' is [5, 2].
Example 2:
Input: [2, 1, 5, 2, 8], S=7 
Output: 1
Explanation: The smallest subarray with a sum greater than or equal to '7' is [8].
Example 3:
Input: [3, 4, 1, 1, 6], S=8 
Output: 3
Explanation: Smallest subarrays with a sum greater than or equal to '8' are [3, 4, 1] 
or [1, 1, 6].
**/
class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    int l=0, r=0, sum =0;
    int mn = INT_MAX;
    while(r<arr.size()) {
      sum += arr[r];
      while (sum >= S) {
        mn = min(mn, r - l + 1);
        sum -= arr[l++];
      }
      r++;
    }
    return mn==INT_MAX?0:mn;
  }
};
