/**
https://www.interviewbit.com/problems/rain-water-trapped/
Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.
Problem Constraints
1 <= |A| <= 100000
Input Format: The only argument given is integer array A.
Output Format: Return the total water it is able to trap after raining.
Example Input
Input 1: A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Input 2: A = [1, 2]
Example Output
Output 1:6
Output 2: 0
Example Explanation
Explanation 1: In this case, 6 units of rain water (blue section) are being trapped.
Explanation 2: No water is trapped.
**/
class Solution {
public:
  int trap(vector<int>& A) {
    if(A.size() == 0) return 0;
    vector<int> maxLeft(A.size(), 0);
    vector<int> maxRight(A.size(), 0);

    maxLeft[0] = A[0];
    for(int i=1; i<A.size(); i++) {
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

int Solution::trap(const vector<int> &A) {
  int ans = 0;
  int left = 0, right = A.size()-1;
  int leftMax = INT_MIN, rightMax = INT_MIN;
  while(left <= right) {
    if(A[left] < A[right]) {
      if(A[left] > leftMax)
        leftMax = A[left];
      else
        ans += leftMax - A[left];
      left++;
    }
    else {
      if(A[right] > rightMax)
        rightMax = A[right];
      else
        ans += rightMax - A[right];
      right--;
    }
  }
  return ans;
}
