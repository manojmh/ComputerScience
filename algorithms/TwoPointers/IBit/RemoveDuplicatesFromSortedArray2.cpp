/**
https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/
Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
Note that even though we want you to return the new length, make sure to change the original array as well in place
For example,
Given input array A = [1,1,1,2],
Your function should return length = 3, and A is now [1,1,2].
**/
int Solution::removeDuplicates(vector<int> &A) {
  int n = A.size();
  if(n==0 || n==1) return n;

  int j=0;
  int count = 0;
  for(int i=0; i<n-1; i++) {
    if(A[i]!=A[i+1]) {
      A[j++] = A[i];
      count = 0;
    }
    else {
      if(count <1)
        A[j++] = A[i];
      count++;
    }
  }
  A[j++] = A[n-1];
  return j;
}
//Simple Solution editorial
int removeDuplicates(int A[], int n) {
  int j = 0;
  for (int i = 0; i < n; i++) { 
    if (i < n - 2 && A[i] == A[i+1] && A[i] == A[i+2])
      continue;
    else {
        A[j] = A[i];
        j++;
    }
  }
  return j;
}
