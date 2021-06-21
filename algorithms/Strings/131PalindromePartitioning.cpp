/**
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.
A palindrome string is a string that reads the same backward as forward.
Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:
Input: s = "a"
Output: [["a"]]
Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.

Intution : Simple backtracking
**/
class Solution {
public:
  bool isPal(string s, int i, int j) {
    while(i<j) {
      if(s[i++]!=s[j--])
          return false;
    return true;
  }
  void allPalPartUtil(string s, vector<vector<string>> &all, vector<string> out, int i, int n) {
    if(i>=n) {
      all.push_back(out);
      return;
    }
    for (int j=i; j<n; j++) {
      if(isPal(s, i, j)) {
        out.push_back(s.substr(i,j-i+1));
        allPalPartUtil(s, all, out, j+1, n);
        out.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s) {
    int n = s.length();
    vector<vector<string> > allPart;
    vector<string> currPart;
    allPalPartUtil(s,allPart, currPart, 0, n);
    return allPart;
  }
};
