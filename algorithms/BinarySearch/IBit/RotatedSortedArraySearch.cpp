/**
https://www.interviewbit.com/problems/rotated-sorted-array-search/
Given an array of integers A of size N and an integer B.
array A is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).
You are given a target value B to search. If found in the array, return its index, otherwise return -1.
You may assume no duplicate exists in the array.
NOTE:- Array A was sorted in non-decreasing order before rotation.
NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*
Input Format
The first argument given is the integer array A.
The second argument given is the integer B.
Output Format
Return index of B in array A, otherwise return -1
Constraints
1 <= N <= 1000000
1 <= A[i] <= 10^9
all elements in A are disitinct.
For Example
Input 1:
    A = [4, 5, 6, 7, 0, 1, 2, 3]
    B = 4
Output 1:
    0
Explanation 1:
 Target 4 is found at index 0 in A.
Input 2:
    A = [5, 17, 100, 3]
    B = 6
Output 2:
    -1
**/
int Solution::search(const vector<int> &A, int B) {
  int i = 0;
  for(i=0; i<A.size(); i++) {
    if(A[i] == B) return i;
    if(A[0] > A[i])
        break;
  }
  int low = i, high = A.size();
  while(low <= high) {
    int mid = low + (high-low)/2;
    if(A[mid] == B) return mid;
    if(A[mid] < B)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}
//Innovative solution:
int Solution::search(const vector<int> &A, int B) {
  if (A.empty())
    return -1;
  const auto pivot = partition_point(A.begin(), A.end(),
                       [&A](int e){return e >= A[0];});
  auto it = lower_bound(A.begin(), pivot, B);
  if (it != A.end() && *it == B)
    return it - A.begin();
  it = lower_bound(pivot, A.end(), B);
  if (it != A.end() && *it == B)
    return it - A.begin();
  return -1;
}
//Editorial
int Solution::search(const vector<int> &A, int B) {
  int n = A.size();
  int low = 0, high = n-1;
  while(low<=high){
    int mid = low + (high-low)/2;
    if(A[mid] == B) return mid;
    else if(A[0]<=A[mid]){//i.e. left part is sorted
      if(A[0]<=B && B < A[mid])
        high = mid-1;//B lies on left part
      else
        low = mid+1;
    }else{//right part is sorted
      if(A[mid] < B && B<=A[n-1])
        low = mid+1;//B lies on right part
      else 
        high = mid-1;
    }
  }
  return -1;
}
