/**
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
Example:
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
**/
int Solution::isPalindrome(string A) {
  string str;
  for(int i=0; i<A.size(); i++) {
    if(A[i] >= 'A' && A[i] <= 'Z')
      str.push_back(A[i]-'A' + 'a');
    if(A[i] >= 'a' && A[i] <= 'z')
      str.push_back(A[i]);
    if(A[i] >= '0' && A[i] <= '9')
      str.push_back(A[i]);
  }
  int n = str.size()-1;
  for(int i=0; i<=n; i++)
    if(str[i] != str[n-i])
      return 0;
  return 1;
}
