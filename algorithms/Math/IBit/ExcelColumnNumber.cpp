/** Amazon
Given a column title A as appears in an Excel sheet, return its corresponding column number.
Problem Constraints
1 <= |A| <= 100
Input Format
First and only argument is string A.
Output Format
Return an integer
Example Input
Input 1:1
Input 2:28
Example Output
Output 1:"A"
Output 2:"AB"
Example Explanation
Explanation 1:1 -> "A"
Explanation 2:
A  -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
**/
//Sol 1:
int Solution::titleToNumber(string A) {
  int num =0;
  for(int i=0; i<A.length(); i++)
    num += pow(26, i) * (A[A.length()-1-i] - 'A' + 1);
  return num;
}
//Sol 2:
class Solution {
public:
  int titleToNumber(string s) {
   int result = 0;
   for (int i = 0; i < s.size(); i++) {
     result = result * 26 + (s[i] - 'A' + 1);
   }
   return result;
  }
};
