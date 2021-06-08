/**
https://www.interviewbit.com/problems/maximum-unsorted-subarray/
You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.
Example :
Input 1:
A = [1, 3, 2, 4, 5]
Return: [1, 2]
Input 2:
A = [1, 2, 3, 4, 5]
Return: [-1]
In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.
**/
vector<int> Solution::subUnsort(vector<int> &A) {
  vector<int> a(A.begin(),A.end());
  sort(a.begin(),a.end());
  int i=0,j=A.size()-1;
  while(i<=j){
    if(A[i]!=a[i] && A[j]!=a[j])
      break;
    if(a[i]==A[i])
      i++;
    if(a[j]==A[j])
      j--;
  }
  if(i>j) return {-1};
  return {i,j};
}
