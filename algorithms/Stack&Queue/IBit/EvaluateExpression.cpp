/**
https://www.interviewbit.com/problems/evaluate-expression/
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
Input Format : The only argument given is character array A.
Output Format: Return the value of arithmetic expression formed using reverse Polish Notation.
For Example: Input 1: A =   ["2", "1", "+", "3", "*"] Output 1: 9
Explaination 1:
    starting from backside:
    *: ( )*( )
    3: ()*(3)
    +: ( () + () )*(3)
    1: ( () + (1) )*(3)
    2: ( (2) + (1) )*(3)
    ((2)+(1))*(3) = 9
Input 2:
    A = ["4", "13", "5", "/", "+"]
Output 2:
    6
Explaination 2:
    +: ()+()
    /: ()+(() / ())
    5: ()+(() / (5))
    1: ()+((13) / (5))
    4: (4)+((13) / (5))
    (4)+((13) / (5)) = 6
**/
bool isNumber(string s)
{
  if(s.length() == 1 && isdigit(s[0]) == false)
    return false;
  for (int i = 0; i < s.length(); i++) {
    if(i==0 && s[i]=='-') continue;
    if (isdigit(s[i]) == false)
      return false;
  }
  return true;
}
int Solution::evalRPN(vector<string> &A) {
  stack<int> s;
  for(int i=0; i<A.size(); i++) {
    if(isNumber(A[i]))
      s.push(stoi(A[i]));
    else {
      int op1 = 0, op2 = 0;
      if(!s.empty()) {
        op2 = s.top();
        s.pop();
      }
      if(!s.empty()) {
        op1 = s.top();
        s.pop();
      }
      if(A[i] == "+") s.push((op1+op2));
      if(A[i] == "-") s.push((op1-op2));
      if(A[i] == "*") s.push((op1*op2));
      if(A[i] == "/") s.push((op1/op2));
    }
  }
  if(!s.empty()) return s.top();
  return 0;
}
