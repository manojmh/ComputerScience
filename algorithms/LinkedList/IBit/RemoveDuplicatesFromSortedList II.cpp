/**
https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/
Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
**/
ListNode* Solution::deleteDuplicates(ListNode *head) {
  if (head == NULL) return NULL;
  ListNode* fakeHead = new ListNode(0);
  fakeHead->next = head;
  ListNode* pre = fakeHead;
  ListNode* cur = head;
  while (cur != NULL) {
    while (cur->next != NULL && cur->val == cur->next->val) {
      cur = cur->next;
    }
    if (pre->next == cur) {
      pre = pre->next;
    } else {
      pre->next = cur->next;
    }
    cur = cur->next;
  }
  return fakeHead->next;
}
