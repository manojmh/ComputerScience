/**
https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/
Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space.
You may not modify the values in the list, only nodes itself can be changed.
**/
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode* start = new ListNode(0); //make head no longer a special case
    start->next = head;

    ListNode *cur = start;
    while (cur->next != NULL && cur->next->next != NULL) {
      cur->next = swap(cur->next, cur->next->next);
      cur = cur->next->next;
    }
    return start->next;
  }
  ListNode* swap(ListNode* next1, ListNode* next2) {
    next1->next = next2->next;
    next2->next = next1;
    return next2;
  }
};
//My solution:
ListNode* Solution::swapPairs(ListNode* A) {
  if(!A) return A;
  if(!(A->next)) return A;
  ListNode *a = new ListNode(0), *cura = a;
  ListNode *b = new ListNode(0), *curb = b;
  bool flag = true;
  ListNode *cur = A;
  while(cur) {
    if(flag) {
      cura->next = cur;
      cura = cura->next;
      flag = false;
    }
    else {
      curb->next = cur;
      curb = curb->next;
      flag = true;
    }
    cur = cur->next;
  }
  if(cura)
    cura->next = nullptr;
  if(curb)
    curb->next = nullptr;
  cura = a->next;
  curb = b->next;
  cur = new ListNode(0);
  flag = false;
  while(cura && curb) {
    if(flag) {
      cur->next = cura;
      cura = cura->next;
      flag = false;
    }
    else {
      ListNode *temp = curb->next;
      cur->next = curb;
      curb = curb->next;
      flag = true;
    }
    cur = cur->next;
  }
  if(flag)
    cur->next = cura;
  else
    cur->next = curb;
  return b->next;
}
