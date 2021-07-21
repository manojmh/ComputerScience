/**
https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
Given a string s. In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.
A Palindrome String is one that reads the same backward as well as forward.
Example 1:
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.
Example 2:
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
Example 4:
Input: s = "g"
Output: 0
Example 5:
Input: s = "no"
Output: 1
Constraints:
1 <= s.length <= 500
All characters of s are lower case English letters.
**/
static const auto ______ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
  int lcs(string s1, string s2) {
    int n = s1.length();
    int t[n+1][n+1];
    for(int i=0; i<=n; i++) {
      for(int j=0; j<=n; j++) {
        if(i==0 || j==0)
          t[i][j] = 0;
        else {
          if(s1[i-1] == s2[j-1])
            t[i][j] = t[i-1][j-1] + 1;
          else
            t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
      }
    }
    return t[n][n];
  }
  int minInsertions(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    int n = s.length();
    return n-lcs(s, rev);
  }
};
