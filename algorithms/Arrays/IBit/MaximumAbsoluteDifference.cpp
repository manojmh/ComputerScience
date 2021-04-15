/**
https://www.interviewbit.com/problems/maximum-absolute-difference/
You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.
For example,
A=[1, 3, -1]
f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5
So, we return 5.

Hint:
Refer to : https://en.wikipedia.org/wiki/Absolute_value
f(i, j) = |A[i] - A[j]| + |i - j| can be written in 4 ways
(Since we are looking at max value, we don’t even care if the value becomes negative as long as we are also covering the max value in some way).
(A[i] + i) - (A[j] + j)
-(A[i] - i) + (A[j] - j) 
(A[i] - i) - (A[j] - j) 
(-A[i] - i) + (A[j] + j) = -(A[i] + i) + (A[j] + j)
Note that case 1 and 4 are equivalent and so are case 2 and 3.
We can construct two arrays with values: A[i] + i and A[i] - i.
Then, for above 2 cases, we find the maximum value possible.
For that, we just have to store minimum and maximum values of expressions A[i] + i and A[i] - i for all i.
**/
int Solution::maxArr(vector<int> &A) {
  int mx1=INT_MIN,mx2=INT_MIN;
  int mn1=INT_MAX,mn2=INT_MAX;
  for(int i=0;i<A.size();i++){
    mx1=max(mx1,A[i]+i);
    mx2=max(mx2,A[i]-i);
    mn1=min(mn1,A[i]+i);
    mn2=min(mn2,A[i]-i);
  }
  return max(mx1-mn1,mx2-mn2);
}
