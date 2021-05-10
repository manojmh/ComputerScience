/**
https://www.interviewbit.com/problems/add-two-numbers-as-lists/
You are given two linked lists representing two non-negative numbers. \
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.
**/
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
  if(!A) return B;
  if(!B) return A;
  ListNode *c1 = A, *c2 = B, *C = new ListNode(0), *c3 = C;
  int carry = 0;
  while(c1 && c2) {
    int sum = c1->val + c2->val + carry;
    c3->next = new ListNode(sum % 10);
    carry = sum /10;
    c3 = c3->next;
    c1 = c1->next;
    c2 = c2->next;
  }
  while(c1) {
    int sum = c1->val + carry;
    c3->next = new ListNode(sum % 10);
    carry = sum /10;
    c3 = c3->next;
    c1 = c1->next;
  }
  while(c2) {
    int sum = c2->val + carry;
    c3->next = new ListNode(sum % 10);
    carry = sum /10;
    c3 = c3->next;
    c2 = c2->next;
  }
  while(carry) {
    c3->next = new ListNode(carry%10);
    carry = carry/10;
  }
  C = C->next;
  return C;
}
