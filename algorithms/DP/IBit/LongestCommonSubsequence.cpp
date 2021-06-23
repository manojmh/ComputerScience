/**
Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings.
You need to return the length of such longest common subsequence.
Problem Constraints
1 <= |A|, |B| <= 1005
Input Format
First argument is an string A.
Second argument is an string B.
Output Format
Return the length of such longest common subsequence between string A and string B.
Example Input
Input 1:
A = "abbcdgf"
B = "bbadcgf"
Example Output
Output 1: 5
0 0 b b a d c g f
0 0 0 0 0 0 0 0 0 
a 0 0 0 1 1 1 1 1 
b 0 1 1 1 1 1 1 1 
b 0 1 2 2 2 2 2 2 
c 0 1 2 2 2 3 3 3 
d 0 1 2 2 3 3 3 3
g 0 1 2 2 3 3 4 4
f 0 1 2 2 3 3 4 5
5
Example Explanation
Explanation 1:
The longest common subsequence is "bbcgf", which has a length of 5
**/
int Solution::solve(string A, string B) {
  int m=A.size(), n=B.size();
  int t[m+1][n+1];
  for(int i=0; i<=m; i++) {
    for(int j=0; j<=n; j++) {
      if(i==0 || j==0)
        t[i][j] = 0;
      else if(A[i-1]==B[j-1])
        t[i][j] = 1 + t[i-1][j-1];
      else
        t[i][j] = max(t[i-1][j], t[i][j-1]);
      cout << t[i][j] << " ";
    }
    cout << endl;
  }
  return t[m][n];
}
