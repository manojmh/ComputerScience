/**
https://www.interviewbit.com/old/problems/majority-element/
Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.
Example :
Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2.
Moor's Voting Algorithm
**/
int Solution::majorityElement(const vector<int> &A) {
  int major = A[0];
  int count = 1;
  for(int i=1;i<A.size();i++) {
    if(major == A[i])
      count++;
    else
      count--;
    if(count == 0) {
      major = A[i];
      count = 1;
    }
  }
  return major;
}
