/**
https://www.educative.io/courses/grokking-the-coding-interview/JPKr0kqLGNP
Given an array of positive numbers and a positive number ‘k,’ find the maximum sum of any contiguous subarray of size ‘k’.
Example 1:
Input: [2, 1, 5, 1, 3, 2], k=3 
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].
Example 2:
Input: [2, 3, 4, 1, 5], k=2 
Output: 7
Explanation: Subarray with maximum sum is [3, 4].
**/
using namespace std;

#include <iostream>
#include <vector>

class MaxSumSubArrayOfSizeK {
 public:
  static int findMaxSumSubArray(int k, const vector<int>& arr) {
    int sum = 0;
    int maxSum = 0;
    for(int i=0; i<k; i++)
      maxSum += arr[i];
    sum = maxSum;
    for(int i=k, j=0; i<arr.size(); i++, j++) {
      cout << arr[j] << " " << arr[i] << endl;
      sum += arr[i];
      sum -= arr[j];
      maxSum = max(maxSum, sum);
    }
    return maxSum;
  }
};
