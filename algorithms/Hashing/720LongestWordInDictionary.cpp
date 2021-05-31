/**
https://leetcode.com/problems/longest-word-in-dictionary/
Given an array of strings words representing an English Dictionary,
return the longest word in words that can be built one character at a time by other words in words.
If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.
Example 1:
Input: words = ["w","wo","wor","worl","world"]
Output: "world"
Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:
Input: words = ["a","banana","app","appl","ap","apply","apple"]
Output: "apple"
Explanation: Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
Constraints:
1 <= words.length <= 1000
1 <= words[i].length <= 30
words[i] consists of lowercase English letters.
**/
class Solution {
public:
  string longestWord(vector<string>& words) {
    int maxLen = 0;
    unordered_set<string> s;
    map<int, set<string>> m;
    for(auto w : words)
      s.insert(w);
    string maxWord = "";
    string temp = "";
    for(int i=0; i<words.size(); i++) {
      for(int j=0; j<words[i].size(); j++) {
        temp += words[i][j];
        if(s.find(temp) == s.end()) {
          temp = "";
        }else if(temp.length() >= maxWord.length()) {
          maxWord = temp;
          m[temp.length()].insert(temp);
          maxLen = temp.length();
        }
      }
      temp = "";
    }
    return *(m[maxLen].begin());
  }
};
