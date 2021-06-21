/**
https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#
Matrix Chain Multiplication 
Hard Accuracy: 67.56% Submissions: 8663 Points: 8
Given a sequence of matrices, find the most efficient way to multiply these matrices together.
The efficient way is the one that involves the least number of multiplications.
The dimensions of the matrices are given in an array arr[] of size N
(such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

Example 1:
Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
Explaination: There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.

Example 2:
Input: N = 4
arr = {10, 30, 5, 60}
Output: 4500
Explaination: The matrices have dimensions 
10*30, 30*5, 5*60. Say the matrices are A, B 
and C. Out of all possible combinations,the
most efficient way is (A*B)*C. The 
number of multiplications are -
10*30*5 + 10*5*60 = 4500.

Your Task:
You do not need to take input or print anything.
Your task is to complete the function matrixMultiplication()
which takes the value N and the array arr[] as input parameters and returns
the minimum number of multiplication operations needed to be performed.
Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N2)
Constraints: 
2 ≤ N ≤ 100
1 ≤ arr[i] ≤ 500
Company Tags
FactSet Flipkart Microsoft
Topic Tags
Dynamic Programming Matrix
Related Courses
Must Do Interview Preparation Microsoft SDE Test Series
Related Interview Experiences
Microsoft interview experience set 128 campus internship
**/
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
  long long solve(int arr[], int i, int j, vector<vector<long long>> &T) {
    if(i>=j)
      return 0;
    if(T[i][j] != -1) return T[i][j];
    T[i][j] = LONG_MAX-1;
    for(int k=i; k<=j-1; k++) {
      T[i][j] = min(T[i][j],solve(arr, i, k, T) + 
                            solve(arr, k+1, j, T) + 
                            arr[i-1]*arr[k]*arr[j]);
    }
    return T[i][j];
  }
  int matrixMultiplication(int N, int arr[]) {
    vector<vector<long long>> T(N, vector<long long>(N, -1));
    if(N>1)
      return solve(arr, 1, N-1, T);
    return arr[0];
  }
};
int main(){
  int t;
  cin>>t;
  while(t--){
    int N;
    cin>>N;
    int arr[N];
    for(int i = 0;i < N;i++)
      cin>>arr[i];
    Solution ob;
    cout<<ob.matrixMultiplication(N, arr)<<endl;
  }
  return 0;
}
