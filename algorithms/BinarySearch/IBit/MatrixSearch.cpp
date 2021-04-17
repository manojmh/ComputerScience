/**
https://www.interviewbit.com/problems/matrix-search/
Given a matrix of integers A of size N x M and an integer B.
Write an efficient algorithm that searches for integar B in matrix A.
This matrix A has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Return 1 if B is present in A, else return 0.
Note: Rows are numbered from top to bottom and columns are numbered from left to right.
Input Format
The first argument given is the integer matrix A.
The second argument given is the integer B.
Output Format
Return 1 if B is present in A, else return 0.
Constraints
1 <= N, M <= 1000
1 <= A[i][j], B <= 10^6
For Example
Input 1:
A = 
  [ [1,   3,  5,  7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]  ]
B = 3
Output 1: 1
Input 2:
    A = [   [5, 17, 100, 111]
            [119, 120,  127,   131]    ]
    B = 3
Output 2: 0
**/
int Solution::searchMatrix(vector<vector<int>> &A, int B) {
  int start=0,end=A.size()-1,m=A[0].size()-1;
  while(start<end){
    int mid=(start+end)/2;
    if(A[mid][m]==B)return 1; // comparing the last element of each row finding the right row
    else if(A[mid][m]<B){
      start=mid+1;
    }
    else {
      end=mid;
    }
  }
  int j=0; // finding the element in the right row
  for(j=0;j<A[0].size();j++){
    if(A[start][j]==B){
      return 1;
    }
  }
  return 0;
}
//Editorial:
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
  int N=A.size();
  int M=A[0].size();
  int start=0, end=N*M-1;
  while(start<=end){
    int mid=start+(end-start)/2;
    int x=mid/M;
    int y=mid%M;
    if(A[x][y]==B) return 1;
    if(B<A[x][y]) end=mid-1;
    else start=mid+1;
  }
  return 0;
}
