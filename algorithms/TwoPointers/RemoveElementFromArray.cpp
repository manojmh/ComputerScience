/**
Remove Element
Given an array and a value, remove all the instances of that value in the array.
Also return the number of elements left in the array after the operation.
It does not matter what is left beyond the expected length.
Example:
If array A is [4, 1, 1, 2, 1, 3]
and value elem is 1,
then new length is 3, and A is now [4, 2, 3] 
Try to do it in less than linear additional space complexity.
**/
int Solution::removeElement(vector<int> &A, int B) {
  int i = 0, j=0;
  int n = A.size();
  while(j<n) {
    if(A[j]!=B) {
      A[i] = A[j];
      i++;
    }
    j++;
  }
  return i;
}
//Editorial
int Solution::removeElement(vector<int> &A, int B) {
  int i = 0;
  for (int j = 0; j < A.size(); j++) {
    if (A[j] != B) {
      A[i] = A[j];
      i++;
    }
  }
  return i;
}
