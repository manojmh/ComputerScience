/** Browser Stack
Given a number A. Find the fatorial of the number.
Problem Constraints
1 <= A <= 100
Input Format
First and only argument is the integer A.
Output Format
Return a string, the factorial of A.
Example Input
Input 1:A = 2
Input 2:A = 3
Example Output
Output 1: 2
Output 2: 6
Example Explanation
Explanation 1:2! = 2 .
Explanation 2:3! = 6 .
**/
string Solution::solve(int A) {
  string solution = "1";
  int product;
  for(int i=2;i<=A;i++) {
    int carry=0;
    for(int j=solution.size()-1;j>=0;j--) {
      product = (i * (solution[j] - '0')) + carry;
      solution[j] = '0' + (product%10);
      carry = product/10;
    }
    if(carry!=0)
      solution = to_string(carry) + solution;
  }
  return solution;
}
