/**
https://www.interviewbit.com/problems/largest-rectangle-in-histogram/
Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of
the ith histogram’s bar. Width of each bar is 1.
Largest Rectangle in Histogram: Example 1
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
Largest Rectangle in Histogram: Example 2
The largest rectangle is shown in the shaded area, which has area = 10 unit.
Find the area of largest rectangle in the histogram.
Input Format : The only argument given is the integer array A.
Output Format : Return the area of largest rectangle in the histogram.
For Example Input 1: A = [2, 1, 5, 6, 2, 3]
Output 1: 10
Explanation 1: The largest rectangle is shown in the shaded area, which has area = 10 unit.
**/
int Solution::largestRectangleArea(vector<int> &A) {
  int i=0, n = A.size();
  int mxArea = 0, area = 0;
  stack<int> s;
  while(i<n) {
    if(s.empty() || A[s.top()] <= A[i])
      s.push(i++);
    else {
      int top = s.top();
      s.pop();
      area = A[top] * (s.empty() ? i : (i-s.top()-1));
      mxArea = max(mxArea, area);
    }
  }
  while(!s.empty()) {
    int top = s.top();
    s.pop();
    area = A[top] * (s.empty() ? i : (i-s.top()-1));
    mxArea = max(mxArea, area);
  }
  return mxArea;
}
