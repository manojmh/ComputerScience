/**
https://www.interviewbit.com/problems/reverse-linked-list/
Reverse a linked list. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL,
return 5->4->3->2->1->NULL.
PROBLEM APPROACH : Complete solution code in the hints
**/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
  ListNode *prev = nullptr, *cur=A, *next=nullptr;
  while(cur) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}
