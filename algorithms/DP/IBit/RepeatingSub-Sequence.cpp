/**
https://www.interviewbit.com/old/problems/repeating-subsequence/
Given a string A, find length of the longest repeating sub-sequence such that the two subsequence don’t have same string character at same position,
i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
NOTE: Sub-sequence length should be greater than or equal to 2.
Problem Constraints
1 <= |A| <= 100
Input Format
The first and the only argument of input contains a string A.
Output Format
Return an integer, 0 or 1:
=> 0 : False
=> 1 : True
Example Input
Input 1: A = "abab"
Input 2: A = "abba"
Example Output
Output 1: 1
Output 2: 0
Example Explanation
Explanation 1: "ab" is repeated.
Explanation 2: There is no repeating subsequence.
Intution: Same as LCS but check i!=j
**/
int Solution::anytwo(string A) {
  int n = A.size();
  int t[n+1][n+1];
  for(int i=0; i<=n; i++) {
    for(int j=0; j<=n; j++) {
      if(i==0 || j==0)
        t[i][j] = 0;
      else if(i!=j && A[i-1] == A[j-1])
        t[i][j] = 1 + t[i-1][j-1];
      else
        t[i][j] = max(t[i-1][j], t[i][j-1]);
      //cout << t[i][j] << " ";
    }
    //cout << endl;
  }
  return t[n][n]>=2;
}
