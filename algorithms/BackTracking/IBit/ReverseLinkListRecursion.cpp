/**
https://www.interviewbit.com/problems/reverse-link-list-recursion/
Reverse a linked list using recursion.
Example :
Given 1->2->3->4->5->NULL,
return 5->4->3->2->1->NULL.
PROBLEM APPROACH :
Complete solution code in the hints
**/
void recursiveReverse(ListNode* head, ListNode** headRef) {
  ListNode* first;
  ListNode* rest;

  // empty list base case
  if (head == NULL) {
    return;
  }

  first = head;           // suppose first = {1, 2, 3}
  rest = first->next;     // rest = {2, 3}

  // base case: the list has only one node
  if (rest == NULL)
  {
    // fix the head pointer here
    *headRef = first;
    return;
  }

  // recursively reverse the smaller {2, 3} case
  // after: rest = {3, 2}
  recursiveReverse(rest, headRef);

  // put the first item at the end of the list
  rest->next = first;
  first->next = NULL;     // (tricky step — make a drawing)
}
ListNode* Solution::reverseList(ListNode* node) {
  recursiveReverse(node, &node);
  return node;
}
