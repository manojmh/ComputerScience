/**
https://leetcode.com/problems/longest-palindromic-substring/
Given a string s, return the longest palindromic substring in s.
Example 1:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: s = "cbbd"
Output: "bb"
Example 3:
Input: s = "a"
Output: "a"
Example 4:
Input: s = "ac"
Output: "a"
Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),

Intution: https://www.youtube.com/watch?v=XmSOWnL6T_I
**/
class Solution {
public:
  string longestPalindrome(string s) {
    int mx = INT_MIN;
    string res;
    vector<vector<bool>> t(s.length(), vector<bool>(s.length(), false));
    for(int g=0; g<=s.length(); g++) {
      for(int i=0, j=g; j<s.length(); i++,j++) {
        if(g==0) {
          t[i][j] = true;
        }
        else if(g==1) {
          if(s[i]==s[j])
            t[i][j] = true;
          else
            t[i][j] = false;
        }
        else {
          if(s[i]==s[j]) {
            if(t[i+1][j-1]==true)
              t[i][j] = true;
            else
              t[i][j] = false;
          }
          else {
            t[i][j] = false;
          }
        }
        if(t[i][j] == true) {
          if(mx < j-i+1) {
            mx = j-i+1;
            res = s.substr(i,j-i+1);
          }
        }
      }
    }
    return res;
  }
};
