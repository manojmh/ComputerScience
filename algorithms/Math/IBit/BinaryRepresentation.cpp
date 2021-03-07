/**
Given a number N >= 0, find its representation in binary.
Example: if N = 6, binary form = 110
**/
string Solution::findDigitsInBinary(int A) {
  if(A < 1) return "0";
  string s="";
  while(A) {
    s.push_back('0' + (A%2));
    A /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}
