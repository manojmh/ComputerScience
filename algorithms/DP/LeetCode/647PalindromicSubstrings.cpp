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

Intution: https://www.youtube.com/watch?v=XmSOWnL6T_I
**/
class Solution {
public:
  int countSubstrings(string s) {
    int count = 0;
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
            count++;
        }
      }
    }
    return count;
  }
};
