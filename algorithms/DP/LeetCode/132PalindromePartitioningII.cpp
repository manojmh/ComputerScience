/**
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
Example 1:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:
Input: s = "a"
Output: 0
Example 3:
Input: s = "ab"
Output: 1
Constraints:
1 <= s.length <= 2000
s consists of lower-case English letters only.
**/
class Solution {
public:
  int minCut(string s) {
    int n = s.length();
    bool dp[n][n];
    for(int g=0; g<n; g++) {
      for(int i=0,j=g; j<n; i++,j++) {
        if(g==0)
          dp[i][j] = true;
        else if(g==1)
          dp[i][j] = (s[i]==s[j]);
        else
          dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
      }
    }
    int strg[n];
    strg[0] = 0;
    for(int j=1; j<n; j++) {
      if(dp[0][j]) {
        //if already a palindrome no cut is required
        strg[j] = 0;
        continue;
      }
      //if not palindrome then find out with how many min cuts
      //can it be converted into palindrome
      int mn = INT_MAX;
      for(int i=j; i>=1; i--) {
        if(dp[i][j]) {
          if(strg[i-1] < mn)
            mn = strg[i-1];
        }
      }
      strg[j] = mn+1;
    }
    return strg[n-1];
  }
};
