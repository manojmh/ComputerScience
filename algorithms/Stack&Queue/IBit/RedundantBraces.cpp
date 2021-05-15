/**
https://www.interviewbit.com/problems/redundant-braces/
Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.
Chech whether A has redundant braces or not.
Return 1 if A has redundant braces, else return 0.
Note: A will be always a valid expression.
Input Format : The only argument given is string A.
Output Format : Return 1 if string has redundant braces, else return 0.
For Example
Input 1: A = "((a + b))"
Output 1: 1
Explanation 1: ((a + b)) has redundant braces so answer will be 1.
Input 2: A = "(a + (a + b))"
Output 2: 0
Explanation 2: (a + (a + b)) doesn't have have any redundant braces so answer will be 0.
**/
bool isSymbol(char s) {
  if(s == '+' || s == '-' || s == '*' || s == '/')
    return true;
  return false;
}

int Solution::braces(string A) {
  stack<char> st;
  for(int i=0; i<A.length(); i++) {
    if(isSymbol(A[i]) || A[i] == '(')
      st.push(A[i]);
    else if(A[i] == ')') {
      if(st.top() == '(')
        return true;
      while(!st.empty() && isSymbol(st.top()))
        st.pop();
      st.pop();
    }
  }
  return false;
}
