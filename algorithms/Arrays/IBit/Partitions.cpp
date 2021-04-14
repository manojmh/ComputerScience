/**
https://www.interviewbit.com/problems/partitions/
You are given a 1D integer array B containing A integers.
Count the number of ways to split all the elements of the array into 3 contiguous parts so that the sum of elements in each part is the same.
Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n])
Problem Constraints
1 <= A <= 105
-109 <= B[i] <= 109
Input Format
First argument is an integer A.
Second argument is an 1D integer array B of size A.
Output Format
Return a single integer denoting the number of ways to split the array B into three parts with the same sum.
Example Input
Input 1: A = 5 B = [1, 2, 3, 0, 3]
Input 2: A = 4 B = [0, 1, -1, 0]
Example Output
Output 1:2
Output 2: 1
Example Explanation
Explanation 1:
There are no 2 ways to make partitions -
1. (1,2)+(3)+(0,3).
2. (1,2)+(3,0)+(3).
Explanation 2:
There is only 1 way to make partition -
1. (0)+(-1,1)+(0).

Solution explaination:
First of all find the prefix sum as it will help later to detect whether partition with given sum occurs or not.
Also the last value of prefix array will provide us with the total sum of array.
Now, since we have to divide the array into 3 contiguous subarrays having equal sum,
it is clear that the sum of the individual subarrays will be (total sum of the array) / 3.
Also, if total sum of array is not divisible by 3 then answer will be zero.
Now we have the sum of individual subarrays with us and also v = 2* (s[A] / 3)is just the sum of 2 partitions.
Notice that answer is updated when we have prefix sum which is equal to v and the count is updated when we encounter a prefix sum of u which is s[A] / 3.
Now why this thing? This is because:
Consider this example:
1, 2, 3, 0, 3
Prefix array:
1, 3, 6, 6, 9
Here, u = 9 / 3 = 3 and v = 3*2 = 6.
Coming to the above point: if you didn’t encounter 3 but directly encounter 6 in the prefix array,
the answer will be 0 only as it implies that no partition till that point is there with sum exactly equal to 3.
Consider the below example for better explaination:
Array: 1, 1, 4, 0, 3
Prefix array: 1, 2, 6, 6, 9
Here u and v are same . But since we don’t have any partition with sum 3 hence even after having sum = 6 answer will be zero.
**/
int Solution::solve(int A, vector<int> &B) {
  int n = B.size();
  vector<int> pref(n, 0);
  pref[0] = B[0];
  for(int i=1; i<n; i++)
    pref[i] = pref[i-1] + B[i];
  if(pref[n-1]%3 != 0) return 0;
  long long ans = 0, count = 0;
  long long u = pref[n-1] / 3;
  long long v = 2 * u;
  for(int i=0; i<n-1; i++) {
    if(pref[i] == v) //if 2/3rd of the pref is encountered then add the count to ans
      ans += count;
    if(pref[i] == u) //if 1/3rd of pref is encountered then increament the counter
      count++;
  }
  return ans;
}
