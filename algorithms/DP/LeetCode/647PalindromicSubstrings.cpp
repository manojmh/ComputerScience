/**
https://leetcode.com/problems/palindromic-substrings/
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.
Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.

Intution: LPS = LCS(s, reverse(s))
**/
class Solution {
public:
  int lcs(string a, string b) {
    int n = a.length();
    vector<vector<int>> t(n+1, vector<int>(n+1));
    for(int i=0; i<n+1; i++)
      t[i][i] = 0;
    for(int i=1; i<n+1; i++) {
      for(int j=1; j<n+1; j++) {
        if(a[i-1]==b[j-1])
          t[i][j] = 1 + t[i-1][j-1];
        else
          t[i][j] = max(t[i-1][j], t[i][j-1]);
      }
    }
    return t[n][n];
  }
  int longestPalindromeSubseq(string s) {
    string r = s;
    reverse(r.begin(), r.end());
    return lcs(s, r);
  }
};
