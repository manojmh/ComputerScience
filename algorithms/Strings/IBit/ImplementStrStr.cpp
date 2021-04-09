/**
https://www.interviewbit.com/problems/implement-strstr/
Another question which belongs to the category of questions which are intentionally stated vaguely.
Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.
Implement strStr().
strstr - locate a substring ( needle ) in a string ( haystack ). 
Try not to use standard library string functions for this question.
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases. 
**/
int Solution::strStr(const string A, const string B) {
  if(A.length() == 0 || B.length() == 0) return -1;
  int i=0;
  while(i<A.length()) {
    int j = 0;
    while(j<B.length()) {
      if(A[i] == B[j]) {
        i++;
        j++;
      }
      else {
        i -= j;
        i++;
        break;
      }
    }
    if(j==B.length())
      return i-B.size();
  }
  return -1;
}
//Editorial Solution:
int Solution::strStr(const string A, const string B) {
  int start=0;
  int i=0,j=0;
  while(i<A.size() && j<B.size()) {
    if(A[i]==B[j]) {
      i++;
      j++;
    }
    else {
      j=0;
      i=++start;
    }
    if(j==B.size())
      return start;
  }
  return -1;
}
