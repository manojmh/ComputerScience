/**
Given an array of integers A and an integer B.
Find the total number of subarrays having exactly B odd numbers.
Problem Constraints
1 <= length of the array <= 105
1 <= A[i] <= 109
0 <= B <= A
Input Format
The first argument given is the integer array A.
The second argument given is integer B.
Output Format
Return the total number of subarrays having exactly B odd numbers.
Example Input
Input 1: A = [4, 3, 2, 3, 4] B = 2
Input 2: A = [5, 6, 7, 8, 9] B = 3
Example Output
Output 1:4
Output 2: 1
Example Explanation
Explanation 1: The subarrays having exactly B odd numbers are:
[4, 3, 2, 3], [4, 3, 2, 3, 4], [3, 2, 3], [3, 2, 3, 4]
Explanation 2:
The subarrays having exactly B odd numbers is [5, 6, 7, 8, 9]
**/
int Solution::solve(vector<int> &a, int m) {
  int count = 0;
  int prefix[a.size() + 1] = { 0 };
  int odd = 0;
  for (int i = 0; i < a.size(); i++) {
    prefix[odd]++;
    if (a[i] & 1)
      odd++;
    if (odd >= m)
      count += prefix[odd - m];
  } 
  return count;
}
//Editorial:
int Solution::solve(vector<int> &A, int B) {
  unordered_map<int, int> map;
  int curr_sum = 0; //prefix sum
  int count = 0; //count of all subarrays

  for(int i = 0; i<A.size(); i++){
    if(A[i] % 2 == 0) A[i] = 0;
    else A[i] = 1; // odd nos become 1. Now subarrays with sum = B should be found
  }

  for(int i = 0; i<A.size(); i++){
    curr_sum += A[i];
    if(curr_sum == B) count += 1;
    if(map.find(curr_sum - B) != map.end()){
      count += map[curr_sum - B];
    }
    map[curr_sum]++;
  }
  return count;
}
