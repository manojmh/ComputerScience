/**
https://www.interviewbit.com/problems/zigzag-string/
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)
P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows:
string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**Example 2 : **
ABCD, 2 can be written as
A....C
...B....D
and hence the answer would be ACBD.
**/
string Solution::convert(string s, int numRows) {
  if(numRows <= 1)
    return s;
  string res[numRows];
  bool forward = true;
  int j = 0;
  int n = s.length();
  for(int i=0; i<n; i++) {
    if(forward) {
      res[j++].push_back(s[i]);
      if(j == numRows-1)
        forward = false;
    }
    else {
      res[j--].push_back(s[i]);
      if(j==0)
        forward = true;
    }
  }
  string result;
  for(auto &a:res)
    for(auto &b: a)
      result.push_back(b);
  return result;
}
