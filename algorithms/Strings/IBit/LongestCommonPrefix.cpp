/**
https://www.interviewbit.com/problems/longest-common-prefix/
Given the array of strings A,
you need to find the longest string S which is the prefix of ALL the strings in the array.
Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.
For Example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".
Input Format: The only argument given is an array of strings A.
Output Format: Return longest common prefix of all strings in A.
For Example
Input 1: A = ["abcdefgh", "aefghijk", "abcefgh"]
Output 1: "a"
Explanation 1: Longest common prefix of all the strings is "a".
Input 2: A = ["abab", "ab", "abcd"];
Output 2: "ab"
Explanation 2: Longest common prefix of all the strings is "ab".
**/
string Solution::longestCommonPrefix(vector<string> &A) {
  string s = A[0];
  for(int i=1; i<A.size(); i++) {
    int j = 0;
    int len = min(s.length(), A[i].length());
    s.resize(len);
    while(j<len) {
      if(s[j] != A[i][j]) {
        s.resize(j);
        break;
      }
      j++;
    }
  }
  return s;
}
//Editorial Better Approach:
string Solution::longestCommonPrefix(vector<string> &A) 
{
  string s;
  //sorting the strings lexicographically 
  sort(A.begin(),A.end());
  int len = 0;
  int last = A.size()-1;
  len = min(A[0].length(),A[last].length());
  int i=0;
  //first and last string will be most dissimilar thus finding common charcters in these
  while(i<len && A[0][i]==A[last][i]) {
    s+=A[0][i];
    i++;
  }
  return s;
}
