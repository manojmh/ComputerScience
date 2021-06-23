/**
Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.
Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).
Input Format:
The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:
Return an integer representing the answer as described in the problem statement.
Constraints:
1 <= length(A), length(B) <= 700
Example :
Input 1:
A = "abc"
B = "abc"
Output 1: 1
Explanation 1: Both the strings are equal.
Input 2:
A = "rabbbit" 
B = "rabbit"
Output 2: 3
Explanation 2:
These are the possible removals of characters:
=> A = "ra_bbit" 
=> A = "rab_bit" 
=> A = "rabb_it"
Note: "_" marks the removed character.
Intution: https://www.youtube.com/watch?v=-RDzMJ33nx8
**/
int Solution::numDistinct(string A, string B) {
  int m = A.size();
  int n = B.size();
  int t[m+1][n+1];
  memset(t, 0, sizeof(t));
  for(int i=0; i<=m; i++)
    t[i][0] = 1;
  for(int i=1; i<=m; i++) {
    for(int j=1; j<=n; j++) {
      if(A[i-1]==B[j-1]) {
        //char at A is matching with B
        //so we are considering the char at A hence t[i-1][j-1]
        //but there might be one more char at A
        //which is matching with B's current char hence t[i-1][j]
        t[i][j] = t[i-1][j-1] + t[i-1][j];
      }
      else
        t[i][j] = t[i-1][j];
    }
  }
  return t[m][n];
}
//Another Solution
int Solution::numDistinct(string A, string B) {
  int m = A.size();
  int n = B.size();
  int t[m+1][n+1];
  memset(t, 0, sizeof(t));
  for(int i=0;i<=m;i++) t[i][0]=1;
  for(int i=1; i<=m; i++) {
    for(int j=1; j<=n; j++) {
      t[i][j] = t[i-1][j];
      if(A[i-1]==B[j-1])
        t[i][j] += t[i-1][j-1];
    }
  }
  for(int i=0;i<=m;i++) {
    for(int j=0;j<=n;j++) {
        cout << t[i][j] << " ";
    }
    cout << endl;
  }
  return t[m][n];
}
