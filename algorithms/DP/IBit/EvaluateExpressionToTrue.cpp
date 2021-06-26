/**
Given an expression, A, with operands and operators (OR , AND , XOR),
in how many ways can you evaluate the expression to true, by grouping in different ways?
Operands are only true and false.
Return the number of ways to evaluate the expression modulo 103 + 3.
Input Format:
The first and the only argument of input will contain a string, A.
The string A, may contain these characters:
'|' will represent or operator 
'&' will represent and operator
'^' will represent xor operator
'T' will represent true operand
'F' will false
Output:
Return an integer, representing the number of ways to evaluate the string.
Constraints:
1 <= length(A) <= 150
Example:
Input 1: A = "T|F"
Output 1: 1
Explanation 1: The only way to evaluate the expression is:
=> (T|F) = T 
Input 2: A = "T^T^F"
Output 2: 0
Explanation 2: There is no way to evaluate A to a true statement.
**/
unordered_map<string, int> m;
int eval(string A, int s, int e, bool isTrue) {
  if(s>e)
    return false;
  if(s==e) {
    if(isTrue)
      return (A[s] == 'T');
    else
      return (A[s] == 'F');
  }
  string key = to_string(s)+"_"+to_string(e)+"_"+to_string(isTrue);
  if(m.find(key) != m.end())
    return m[key];

  int ans = 0, lt=0, rt=0, lf=0, rf=0;
  for(int k=s+1; k<=e-1; k+=2) {
    lt = eval(A, s, k-1, true);
    rt = eval(A, k+1, e, true);
    lf = eval(A, s, k-1, false);
    rf = eval(A, k+1, e, false);
    if(A[k] == '|') {
      if(isTrue)
        ans = (ans + lt * rf + lf * rt + lt * rt)%1003;
      else
        ans = (ans + lf * rf)%1003;
    }
    else if(A[k] == '&') {
      if(isTrue)
        ans = (ans + lt * rt)%1003;
      else
        ans = (ans + lt * rf + lf * rt + lf * rf)%1003;
    }
    else if(A[k] == '^') {
      if(isTrue)
        ans = (ans + lt * rf + lf * rt)%1003;
      else
        ans = (ans + lt * rt + lf *rf)%1003;
    }
  }
  return m[key] = ans%1003;
}
int Solution::cnttrue(string A) {
  m.clear();
  return eval(A, 0, A.length()-1, true);
}
