/**
https://www.educative.io/courses/grokking-the-coding-interview/YQQwQMWLx80
Given a string, find the length of the longest substring in it with no more than K distinct characters.
You can assume that K is less than or equal to the length of the given string.
Example 1:
Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".
Example 2:
Input: String="araaci", K=1
Output: 2
Explanation: The longest substring with no more than '1' distinct characters is "aa".
Example 3:
Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".
**/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class LongestSubstringKDistinct {
 public:
  static int findLength(const string& s, int k) {
    int maxLength = 0;
    int l=0, r=0, mx=0;
    unordered_map<char, int> m;
    while(r<s.length()) {
      m[s[r]]++;
      if(m.size() == k) {
        maxLength = max(maxLength, r-l+1);
      }
      else if(m.size()>k) {
        m[s[l]]--;
        if(m[s[l]] == 0)
          m.erase(s[l]);
        l++;
      }
      r++;
    }
    return maxLength;
  }
};
