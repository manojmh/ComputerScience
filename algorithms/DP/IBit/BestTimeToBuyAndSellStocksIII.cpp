/**
Say you have an array, A, for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most 2 transactions.
Return the maximum possible profit.
Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
Input Format: The first and the only argument is an integer array, A.
Output Format: Return an integer, representing the maximum possible profit.
Constraints:
1 <= length(A) <= 7e5
1 <= A[i] <= 1e7
Examples:
Input 1: A = [1, 2, 1, 2]
Output 1: 2
Explanation 1: 
Day 0 : Buy 
Day 1 : Sell
Day 2 : Buy
Day 3 : Sell
Input 2: A = [7, 2, 4, 8, 7]
Output 2: 6
Explanation 2:
Day 1 : Buy
Day 3 : Sell
**/
int Solution::maxProfit(const vector<int> &A) {
  if(A.size()<2)
  return 0;
  int s1=A[0],s2=INT_MIN,s3=INT_MIN,s4=INT_MIN;
  for(int i=1;i<A.size();i++) {
    s1=min(s1,A[i]);
    s2=max(s2,A[i]-s1);
    s3=max(s3,s2-A[i]);
    s4=max(s4,s3+A[i]);
  }
  return max(0,max(s2,s4));
}
