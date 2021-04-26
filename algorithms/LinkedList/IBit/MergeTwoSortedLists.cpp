/**
https://www.interviewbit.com/problems/merge-two-sorted-lists/
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.
For example, given following linked lists :
5 -> 8 -> 20 
4 -> 11 -> 15
The merged list should be :
4 -> 5 -> 8 -> 11 -> 15 -> 20
**/
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
  if(!A) return B;
  if(!B) return A;
  ListNode *head = nullptr, *cur = nullptr;
  ListNode *curA = A;
  ListNode *curB = B;
  if(curA->val <= curB->val) {
    cur = curA;
    curA = curA->next;
  }
  else {
    cur = curB;
    curB = curB->next;
  }
  if(!head) head = cur;
  while(curA && curB) {
    if(curA->val <= curB->val) {
      ListNode *temp = curA;
      curA = curA->next;
      cur->next = temp;
    }
    else {
      ListNode *temp = curB;
      curB = curB->next;
      cur->next = temp;
    }
    cur = cur->next;
  }
  if(curA)
    cur->next = curA;
  if(curB)
    cur->next = curB;
  return head;
}
