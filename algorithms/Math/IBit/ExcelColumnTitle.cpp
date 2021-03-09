/** Amazon
Given a positive integer A, return its corresponding column title as appear in an Excel sheet.
Problem Constraints
1 <= A <= 1000000000
Input Format
First and only argument is integer A.
Output Format
Return a string, the answer to the problem.
Example Input
Input 1:A = 1
Input 2:A = 28
Example Output
Output 1:"A"
Output 2:"AB"
Example Explanation
Explanation 1:1 -> A
Explanation 2:
1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB

Tricky: A-1 is due to 0-1 = -1
If you make 0 -> 26 again, you borrow a value(in this case 26, in decimal number system its a 10 -> just the base).
So you subtract 1 from the previous digit. That is how U becomes T.
Basically in the last step, do A/=26. But if x==26, A-=1 as well.
**/
//Solution1:
string Solution::convertToTitle(int A) {
  string res;
  string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  while(A) {
    int i = (A-1)%26;
    A = (A-1)/26;
    res.push_back(s[i]);
  }
  reverse(res.begin(), res.end());
  return res;
}

//Solution2:
string convertToTitle(int n) {
  string ans;
  while (n) {
    ans = char ((n - 1) % 26 + ‘A’) + ans;
    n = (n - 1) / 26;
  }
  return ans;
}
