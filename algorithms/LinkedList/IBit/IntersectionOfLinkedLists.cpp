/**
https://www.interviewbit.com/old/problems/intersection-of-linked-lists/
Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists:
A:     a1 → a2
               ↘
                 c1 → c2 → c3
               ↗
B: b1 → b2 → b3
begin to intersect at node c1.
Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
**/
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
  int countA=0, countB=0;
  for(ListNode *cur = A; cur!=nullptr; cur= cur->next) countA++;
  for(ListNode *cur = B; cur!=nullptr; cur= cur->next) countB++;
  if(countA >= countB) {
    ListNode *curA = A;
    for(; curA!=nullptr && countA != countB; curA=curA->next) countA--;
    ListNode *curB = B;
    while(curA && curB) {
      if(curA==curB) return curA;
      curA=curA->next;
      curB=curB->next;
    }
  }
  else {
    ListNode *curB = B;
    for(; curB!=nullptr && countA != countB; curB=curB->next) countB--;
    ListNode *curA = A;
    while(curA && curB) {
      if(curA==curB) return curA;
      curA=curA->next;
      curB=curB->next;
    }
  }
}
