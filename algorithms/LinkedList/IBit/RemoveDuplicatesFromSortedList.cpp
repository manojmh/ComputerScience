/**
https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
**/
ListNode* Solution::deleteDuplicates(ListNode* A) {
  if(!A) return A;
  if(!(A->next)) return A;
  ListNode *cur = A;
  while(cur && cur->next) {
    ListNode *next;
    next = cur->next;
    while(next && cur->val == next->val) {
      ListNode *temp = next;
      next = next->next;
      delete temp;
    }
    cur->next = next;
    cur = cur->next;
  }
  return A;
}
//Editorial
ListNode* Solution::deleteDuplicates(ListNode* A) {
  ListNode* current = A;
  ListNode* next_next=NULL;
  if (current == NULL) 
   return A;
  while (current->next != NULL) {
   if (current->val == current->next->val) {
     next_next = current->next->next;
     current->next = next_next;  
   }
   else {
    current = current->next; 
   }
  }
  return A;
}
