/**
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:
Input: s = ""
Output: 0
Constraints:
0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
**/
//Most efficient solution O(n) & space : O(1)
class Solution {
public:
  int longestValidParentheses(string s) {
    int n=s.length();
    int left = 0, right=0, maxLen = 0;
    for(int i=0; i<n; i++) {
      if(s[i]=='(')
        left++;
      else
        right++;
      if(left==right)
        maxLen = max(maxLen, 2*right);
      else if(right > left)
        left=right=0;
    }
    left = right = 0;
    for(int i=n-1; i>=0; i--) {
      if(s[i]=='(')
        left++;
      else
        right++;
      if(left==right)
        maxLen = max(maxLen, 2*left);
      else if(left > right)
        left = right = 0;
    }
    return maxLen;
  }
};

//using Stack O(n) space:O(1)
public class Solution {
  public int longestValidParentheses(String s) {
    int maxans = 0;
    Stack<Integer> stack = new Stack<>();
    stack.push(-1);
    for (int i = 0; i < s.length(); i++) {
      if (s.charAt(i) == '(') {
        stack.push(i);
      } else {
        stack.pop();
        if (stack.empty()) {
          stack.push(i);
        } else {
          maxans = Math.max(maxans, i - stack.peek());
        }
      }
    }
    return maxans;
  }
}
