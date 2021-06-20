/**
https://leetcode.com/problems/shortest-palindrome/
You are given a string s. You can convert s to a palindrome by adding characters in front of it.
Return the shortest palindrome you can find by performing this transformation.
Example 1:
Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:
Input: s = "abcd"
Output: "dcbabcd"
Constraints:
0 <= s.length <= 5 * 104
s consists of lowercase English letters only.
Intution : https://www.youtube.com/watch?v=M0Nwvd-G-tg
**/
class Solution {
public:
  int LPS(string s) {
    vector<int> lps(s.length());
    int len = 0, i=1;
    while(i<s.length()) {
      if(s[i] == s[len]) {
        len++;
        lps[i] = len;
        i++;
      }
      else {
        if(len>0)
          len = lps[len-1];
        else
          i++;
      }
    }
    return lps[s.length()-1];
  }
  string shortestPalindrome(string s) {
    string r = s;
    reverse(r.begin(), r.end());
    string full = s+"#"+r;
    int lps = LPS(full);
    string temp = s.substr(lps);
    reverse(temp.begin(), temp.end());
    string res = temp + s;
    return res;
  }
};
