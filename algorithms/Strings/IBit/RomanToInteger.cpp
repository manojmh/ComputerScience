/**
https://www.interviewbit.com/problems/roman-to-integer/
Given a string A representing a roman numeral.
Convert A into integer.
A is guaranteed to be within the range from 1 to 3999.
NOTE: Read more
details about roman numerals at Roman Numeric System
Input Format: The only argument given is string A.
Output Format : Return an integer which is the integer verison of roman numeral string.
For Example
Input 1: A = "XIV"
Output 1: 14
Input 2: A = "XX"
Output 2: 20
**/
int Solution::romanToInt(string A) {
  map<char, int> m;
  m['M'] = 1000;
  m['D'] = 500;
  m['C'] = 100;
  m['L'] = 50;
  m['X'] = 10;
  m['V'] = 5;
  m['I'] = 1;
  int res = 0;
  int i = 0;
  for(i=0; i<A.size(); i++) {
    if(m[A[i]] >= m[A[i+1]])
      res += m[A[i]];
    else {;
      res += m[A[i+1]] - m[A[i]];
      i++;
    }
  }
  return res;
}
//Editorial:
int romanToInt(string s) {
  int num = 0;
  int size = s.size();
  for (int i = 0; i < size; i++) {
    if (i < (size - 1) && romanCharToInt(s[i]) < romanCharToInt(s[i + 1])) {
      num -= romanCharToInt(s[i]);
    else
      num += romanCharToInt(s[i]);
  }
  return num;
}
int romanCharToInt(char c) {
  switch (c) {
    case 'I':   return 1;
    case 'V':   return 5;
    case 'X':   return 10;
    case 'L':   return 50;
    case 'C':   return 100;
    case 'D':   return 500;
    case 'M':   return 1000;
    default:    return 0;
  }
}
