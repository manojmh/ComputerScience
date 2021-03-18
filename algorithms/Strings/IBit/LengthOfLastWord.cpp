/** Amazon
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.
Example:
Given s = "Hello World",
return 5 as length("World") = 5.
Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.
**/
int Solution::lengthOfLastWord(const string A) {
  int l=A.size(),c=0,p;
  for(int i=l-1;i>=0;i--) {
    if(A[i]!=' ') {p=i; break;}
  }
  for(int i=p;i>=0;i--) {
    if(A[i]<='Z' && A[i]>='A') c++;
    else if(A[i]<='z' && A[i]>='a') c++;
    else break;
  }
  return c;
}

//Editorial solution:
int Solution::lengthOfLastWord(const string A) {
  int cnt=0;
  int i=A.length()-1;
  while(A[i]==' ') //looping from last and encountering a first alphanumeric character
      i--;
  for(;i>=0 && A[i]!=' ';i--) //from that point to the first space encountered
      cnt++;
  return cnt;
}
