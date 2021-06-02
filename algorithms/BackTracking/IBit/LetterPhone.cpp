/**
https://www.interviewbit.com/problems/letter-phone/
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.
Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.
**/
string s[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void helper(vector<string> &A, vector<string> &out, string tempOut, int i, int n) {
  if(i==n) {
    out.push_back(tempOut);
    return;
  }
  for(int j=0; j<A[i].size(); j++) {
    tempOut += A[i][j];
    helper(A, out, tempOut, i+1, n);
    tempOut.erase(tempOut.size()-1);
  }
}
vector<string> Solution::letterCombinations(string A) {
  vector<string> in;
  for(int i=0; i<A.size(); i++) {
    in.push_back(s[A[i]-'0']);
  }
  string temp;
  vector<string> out;
  helper(in, out, temp, 0, A.size());
  return out;
}
