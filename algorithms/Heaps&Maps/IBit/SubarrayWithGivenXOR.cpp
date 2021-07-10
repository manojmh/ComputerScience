/**
https://www.interviewbit.com/old/problems/subarray-with-given-xor/?ref=similar_problems
https://www.youtube.com/watch?v=lO9R5CaGRPY
Given an array of integers A and an integer B.
Find the total number of subarrays having bitwise XOR of all elements equals to B.
Problem Constraints
1 <= length of the array <= 105
1 <= A[i], B <= 109
Input Format
The first argument given is the integer array A.
The second argument given is integer B.
Output Format
Return the total number of subarrays having bitwise XOR equals to B.
Example Input
Input 1:
A = [4, 2, 2, 6, 4]
B = 6
Input 2:
A = [5, 6, 7, 8, 9]
B = 5
Example Output
Output 1:4
Output 2: 2
Example Explanation
Explanation 1: The subarrays having XOR of their elements as 6 are: [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
Explanation 2: The subarrays having XOR of their elements as 2 are [5] and [5, 6, 7, 8, 9]
**/
int Solution::solve(vector<int> &A, int B) {
  int count = 0;
  int xorr = 0;
  map<int, int> m;
  for(auto a:A) {
    xorr = xorr ^ a;
    if(xorr == B)
      count++;

    if(m.find(xorr^B) != m.end()) 
      count += m[xorr^B];
    m[xorr]++;
  }
  return count;
}
