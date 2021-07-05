/**
https://www.interviewbit.com/old/problems/sum-of-fibonacci-numbers/
How many minimum numbers from fibonacci series are required such that sum of numbers should be equal to a given Number N?
Note : repetition of number is allowed.
Example:
N = 4
Fibonacci numbers : 1 1 2 3 5 .... so on
here 2 + 2 = 4 
so minimum numbers will be 2 
**/
#include <bits/stdc++.h>
using namespace std;
int Solution::fibsum(int A) {
  int a = 0, b=1, c=1;
  stack<int> s;
  while(c<=A) {
    c=a+b;
    s.push(c);
    a=b;
    b=c;
  }
  int count = 0;
  while(A>0) {
    while(s.top()>A)
      s.pop();
    A = A-s.top();
    s.pop();
    count++;
  }
  return count;
}
