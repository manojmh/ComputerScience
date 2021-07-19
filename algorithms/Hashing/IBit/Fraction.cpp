/**
https://www.interviewbit.com/old/problems/fraction/
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
Example :
Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"
**/
string Solution::fractionToDecimal(int A, int B) {
  if(A==0) return "0";
  string ans = "";
  if(A<0 ^ B<0)
    ans+='-';
  long N = abs(long(A));
  long D = abs(long(B));
  ans += to_string(N/D);
  if(N%D==0) return ans;
  ans+='.';
  unordered_map<int, int> m;
  long r = N%D;
  while(r) {
    if(m.find(r) != m.end()) {
      ans.insert(m[r], 1, '(');
      ans+=')';
      break;
    }
    m[r] = ans.size();
    r*=10;
    ans += to_string(r/D);
    r%=D;
  }
  return ans;
}
