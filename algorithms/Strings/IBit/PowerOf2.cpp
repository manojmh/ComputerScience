/**
https://www.interviewbit.com/old/problems/power-of-2/
Find if Given number is power of 2 or not.
More specifically, find if given number can be expressed as 2^k where k >= 1.
Input: number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:
return 1 if the number is a power of 2 else return 0
Example:
Input : 128
Output : 1
**/
string mulby2(string s){
  int n = s.size();
  int carry = 0;
  int temp;
  for(int i=n-1;i>=0;i--){
    temp = ((s[i] - '0')*2);
    s[i] = '0'+((temp+carry)%10);
    carry = (temp+carry)/10;
  }
  if(carry)
  s.insert (0, 1, carry+'0');
  return s;
}
int Solution::power(string A) {
  string s = "1";
  while(true){
    s = mulby2(s);
    if(A==s)
      return 1;
    if(s.size()>A.size())
      return 0;
  }
}
