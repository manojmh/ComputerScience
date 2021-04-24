/**
https://www.interviewbit.com/problems/palindrome-list/
Given a singly linked list, determine if its a palindrome.
Return 1 or 0 denoting if its a palindrome or not, respectively.
Notes:
Expected solution is linear in time and constant in space.
For example,
List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.
**/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool isPalindrome(ListNode **start, ListNode *end) {
  if(!start && !end) return true;
  if(!start) return true;
  if(!end) return true;

  if(!isPalindrome(start, end->next)) return false;
  if((*start)->val == end->val) {
    (*start) = (*start)->next;
    return true;
  }
  return false;
}
int Solution::lPalin(ListNode* A) {
  ListNode *temp = A;
  return isPalindrome(&temp, A);
}
