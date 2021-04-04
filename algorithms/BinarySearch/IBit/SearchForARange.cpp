/**
https://www.interviewbit.com/problems/search-for-a-range/
Given a sorted array of integers A(0 based index) of size N, find the starting and ending position of a given integar B in array A.
Your algorithm’s runtime complexity must be in the order of O(log n).
Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].
Input Format
The first argument given is the integer array A.
The second argument given is the integer B.
Output Format
Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].
Constraints
1 <= N <= 10^6
1 <= A[i], B <= 10^9
For Example
Input 1: A = [5, 7, 7, 8, 8, 10] B = 8
Output 1: [3, 4]
Explanation 1:
First occurence of 8 in A is at index 3
Second occurence of 8 in A is at index 4
ans = [3, 4]
Input 2: A = [5, 17, 100, 111] B = 3
Output 2: [-1, -1]
**/
 void bsearchHelp(const vector<int> &A, int B, int low, int high, vector<int> &res) {
  int mid = low + (high-low)/2;
  if(high < low) return;
  if(A[mid] == B) {
    int i = mid;
    while(i>=0 && A[i] == B) {
      res[0] = i;
      i--;
    }
    i = mid;
    while(i<A.size() && A[i] == B) {
      res[1] = i;
      i++;
    }
  }
  else if(A[mid] > B)
    bsearchHelp(A, B, low, mid-1, res);
  else
    bsearchHelp(A, B, mid+1, high, res);
  }

 vector<int> Solution::searchRange(const vector<int> &A, int B) {
  int low = 0;
  int high = A.size();
  vector<int> res(2, -1);
  if(A.size() == 0) return res;
  if(A.size() == 1) {
    if (A[0] == B) {
      res[0]=0, res[1]=0;
      return res;
    }
    else
      return res;
  }
  bsearchHelp(A, B, low, high, res);
  return res;
}
//Editorial better solution:
vector<int> searchRange(const vector<int> &A, int target) {
  int n = A.size();
  int i = 0, j = n - 1;
  vector<int> ret(2, -1);
  // Search for the left one
  while (i < j)
  {
    int mid = (i + j) /2;
    if (A[mid] < target) i = mid + 1;
    else j = mid;
  }
  if (A[i]!=target) return ret;
  else ret[0] = i;

  // Search for the right one
  j = n-1;  // We don't have to set i to 0 the second time.
  while (i < j)
  {
    int mid = (i + j) /2 + 1;   // Make mid biased to the right
    if (A[mid] > target) j = mid - 1;  
    else i = mid;               // So that this won't make the search range stuck.
  }
  ret[1] = j;
  return ret;
}
