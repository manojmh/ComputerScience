/**
https://www.interviewbit.com/old/problems/best-time-to-buy-and-sell-stocks-i/
Say you have an array, A, for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction
(i.e, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Return the maximum possible profit.
Problem Constraints
0 <= len(A) <= 7e5
1 <= A[i] <= 1e7
Input Format
The first and the only argument is an array of integers, A.
Output Format
Return an integer, representing the maximum possible profit.
Example Input
Input 1: A = [1, 2]
Input 2: A = [1, 4, 5, 2, 4]
Example Output
Output 1: 1
Output 2: 4
Example Explanation
Explanation 1: Buy the stock on day 0, and sell it on day 1.
Explanation 2: Buy the stock on day 0, and sell it on day 2.
**/
int Solution::maxProfit(const vector<int> &A) {
  int maxSoFar[A.size()];
  int minSoFar[A.size()];
  for(int i=0; i<A.size(); i++) {
    if(i==0)
      minSoFar[i] = A[i];
    else {
      if(A[i] < minSoFar[i-1])
        minSoFar[i] = A[i];
      else
        minSoFar[i] = minSoFar[i-1];
    }
  }
  for(int i=A.size()-1; i>=0; i--) {
    if(i==A.size()-1)
      maxSoFar[i] = A[i];
    else {
      if(A[i] > maxSoFar[i+1])
        maxSoFar[i] = A[i];
      else
        maxSoFar[i] = maxSoFar[i+1];
    }
  }
  int maxProfit = 0;
  for(int i=0; i<A.size(); i++) {
    maxProfit = max(maxProfit, maxSoFar[i]-minSoFar[i]);
  }
  return maxProfit;
}
