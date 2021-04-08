/**
https://www.interviewbit.com/problems/count-and-say/
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.
21 is read off as one 2, then one 1 or 1211.
Given an integer n, generate the nth sequence.
Note: The sequence of integers will be represented as a string.
Example:
if n = 2,
the sequence is 11.
**/
string Solution::countAndSay(int A) {
  if(A==1) return "1";
  if(A==2) return "11";
  string s = "11";
  for(int i=3; i<=A; i++) {
    int j =0;
    int count = 1;
    string temp;
    while(j+1<=s.length()) {
      //cout << ".";
      while(j<=s.length() && s[j] == s[j+1]) {
        count++;
        j++;
      }
      temp+=to_string(count);
      count = 1;
      temp+=s[j];
      j++;
    }
    s = temp;
  }
  return s;
}
