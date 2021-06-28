/**
https://www.interviewbit.com/old/problems/scramble-string/
Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
Below is one possible representation of A = “great”:
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.
For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that “rgeat” is a scrambled string of “great”.
Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that “rgtae” is a scrambled string of “great”.
Given two strings A and B of the same length, determine if B is a scrambled string of S.
Input Format:
The first argument of input contains a string A.
The second argument of input contains a string B.
Output Format:
Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:
1 <= len(A), len(B) <= 50
Examples:
Input 1:
A = "we"
B = "we"
Output 1: 1
Input 2:
A = "phqtrnilf"
B = "ilthnqrpf"
Output 2: 0
**/
unordered_map<string, bool> m;
int solve(string A, string B) {

  if(A.length() != B.length()) return false;
  if(A==B) return true;
  if(A.length() <= 0) return false;

  string key = A+":"+B;
  if(m.find(key) != m.end())
    return m[key];

  int n = A.size();
  for(int i=1; i<n; i++) {
    if( solve(A.substr(0, i), B.substr(n-i,i)) && 
      solve(A.substr(i, n-i), B.substr(0, n-i))) {
      m[key] = true;
      return true;
    }
    if( solve(A.substr(0, i), B.substr(0, i)) && 
      solve(A.substr(i, n-i), B.substr(i,n-i))) {
      m[key] = true;
      return true;
    }
  }
  m[key] = false;
  return false;
}
int Solution::isScramble(const string A, const string B) {
  m.clear();
  return solve(A, B);
}
