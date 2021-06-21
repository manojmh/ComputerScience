/**
https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1#
Palindromic patitioning 
Hard Accuracy: 52.73% Submissions: 17814 Points: 8
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome.
Determine the fewest cuts needed for palindrome partitioning of given string.
Example 1:
Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
Example 2:
Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".
Your Task:
You do not need to read input or print anything, Your task is to complete the function palindromicPartition()
which takes the string str as input parameter and returns minimum number of partitions required.
Expected Time Complexity: O(n*n) [n is the length of the string str]
Expected Auxiliary Space: O(n*n)
Constraints:
1 ≤ length of str ≤ 500
**/
class Solution{
    int T[505][505];
public:
  bool isPalindrome(string s, int i, int j) {
    while(i<j) {
      if(s[i]!=s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }
  int solve(string s, int i, int j) {
    if(i>=j)
      return 0;

    if(T[i][j] != -1)
      return T[i][j];

    if(isPalindrome(s, i, j))
      return 0;

    int ans = INT_MAX;
    for(int k=i; k<=j-1; k++) {
      int temp = 1 +
                ((T[i][k]!=-1) ? T[i][k] : solve(s, i, k)) + 
                ((T[k+1][j]!=-1) ? T[k+1][j] : solve(s, k+1, j));
      ans = min(ans, temp);
    }
    return T[i][j] = ans;
  }
  int palindromicPartition(string str) {
    int n = str.length();
    for(int i=0; i<n+2; i++)
      for(int j=0; j<n+2; j++)
        T[i][j] = -1;
    return solve(str, 0, n-1);
  }
};
