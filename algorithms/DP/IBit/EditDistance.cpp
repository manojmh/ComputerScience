/**
https://www.interviewbit.com/old/problems/edit-distance/
Given two strings A and B, find the minimum number of steps required to convert A to B.
You have the following 3 operations permitted on a word:
Insert a character
Delete a character
Replace a character
Input Format:
The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:
Return an integer, representing the minimum number of steps required.
Constraints:
1 <= length(A), length(B) <= 450
Examples:
Input 1:
A = "abad"
B = "abac"
Output 1: 1
Explanation 1: Operation 1: Replace d with c.
Input 2:
    A = "Anshuman"
    B = "Antihuman"
Output 2: 2
Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.
**/
map<int, int> m;
int min(int x, int y, int z) { return min(min(x, y), z); }
  int solve(string A, string B, int n1, int n2) {
  if(n1 == 0)
    return n2;
  if(n2 == 0)
    return n1;

  int key = n1*1000 + n2;
  if(m.find(key) != m.end())
    return m[key];

  if(A[n1-1] == B[n2-1])
    return m[key] = solve(A, B, n1-1, n2-1);
  return m[key] = 1 + min(solve(A, B, n1-1, n2), //Insert
                        solve(A, B, n1, n2-1), //Delete
                        solve(A, B, n1-1, n2-1)); //Replace
}
int Solution::minDistance(string A, string B) {
  m.clear();
  return solve(A, B, A.length(), B.length());
}
