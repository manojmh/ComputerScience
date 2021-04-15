/**
https://www.interviewbit.com/problems/counting-subarrays/
Given an array A of N non-negative numbers and you are also given non-negative number B.
You need to find the number of subarrays in A having sum less than B. We may assume that there is no overflow.
Problem Constraints
1 <= N <= 104
1 <= A[i] <= 100
1 <= B <= 108
Input Format
First argument is an integer array A.
Second argument is an integer B.
Output Format
Return an integer denoting the number of subarrays in A having sum less than B.
Example Input
Input 1: A = [2, 5, 6] B = 10
Input 2: A = [1, 11, 2, 3, 15] B = 10
Example Output
Output 1:4
Output 2: 4
Example Explanation
Explanation 1:The subarrays with sum less than B are {2}, {5}, {6} and {2, 5},
Explanation 2:The subarrays with sum less than B are {1}, {2}, {3} and {2, 3}

Hint:
1st case :
If sum is less than B, increment end by one position. So contiguous arrays this step produce are (end – start).
We also add el to previous sum. There are as many such arrays as the length of the window.
2nd case :
If sum becomes greater than or equal to B, this means we need to subtract starting element from sum so that
the sum again becomes less than B. So we adjust the window’s left border by incrementing start.
We follow the same procedure until end < array size.
**/
int Solution::solve(vector<int> &A, int B) {
  int count = 0;
  int i = 0, j = 0;
  int sum_so_far = 0;
  while(i<A.size() && j<A.size()) {
    if(sum_so_far + A[j] < B) {
      sum_so_far += A[j++];
      count += j-i;
    }
    else {
      sum_so_far -= A[i++];
    }
  }
  return count;
}

//Editorial:
int Solution::solve(vector<int> &A, int B) {
  int n = A.size(), res = 0;

  int i = 0, j, sum = 0;
  for(j = 0; j < n; j++){
    sum += A[j];

    while(sum >= B) sum -= A[i++];
    res += (j - i + 1);
  }
  return res;
}
