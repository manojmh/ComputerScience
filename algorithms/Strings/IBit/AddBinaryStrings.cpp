/**
https://www.interviewbit.com/problems/add-binary-strings/
Given two binary strings, return their sum (also a binary string).
Example:a = "100" b = "11"
Return a + b = “111”.
**/
string Solution::addBinary(string A, string B) {
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());

  while(A.size() != B.size()){
    if(A.size() < B.size())
      A.push_back('0');
    else if(A.size() > B.size())
      B.push_back('0');
  }

  int n = A.size();
  if(n == 0) return B;

  string ans;
  int carry = 0, i = 0;

  while(i < n){
    int val = 0;
    val = A[i]-'0' + B[i]-'0';
    val += carry;
    carry = val/2;
    ans.push_back((val%2)+'0');
    i++;
  }

  if(carry != 0) ans.push_back(carry+'0');
  while(ans.size() > 0 && ans[ans.size()-1] == '0') ans.pop_back();
  reverse(ans.begin(), ans.end());
  return ans;
}
