/**
https://www.interviewbit.com/problems/largest-number/
Given a list of non negative integers, arrange them such that they form the largest number.
For example:
Given [3, 30, 34, 5, 9], the largest formed number is 9534330.
Note: The result may be very large, so you need to return a string instead of an integer.
**/
static bool compareNum(string a, string b) {
  return a + b > b + a;
}
string largestNumber(const vector<int> &num) {
  string result;
  vector<string> str;
  for (int i = 0; i < num.size(); i++) {
    str.push_back(to_string(num[i]));
  }
  sort(str.begin(), str.end(), compareNum);
  for (int i = 0; i < str.size(); i++) {
    result += str[i];
  }
  if(result[0] == '0') return "0";
  return result;
}
