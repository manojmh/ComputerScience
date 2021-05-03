/**
https://www.interviewbit.com/problems/sort-list/
Sort a linked list in O(n log n) time using constant space complexity.
Example :
Input : 1 -> 5 -> 4 -> 3
Returned list : 1 -> 3 -> 4 -> 5
**/
ListNode* SortedMerge(ListNode* a, ListNode* b);
void FrontBackSplit(ListNode* source, ListNode** frontRef, ListNode** backRef); 
/* sorts the linked list by changing next pointers (not val) */
void MergeSort(ListNode** headRef) {
  ListNode* head = *headRef;
  ListNode* a;
  ListNode* b;

  /* Base case -- length 0 or 1 */
  if ((head == NULL) || (head->next == NULL)) {
    return;
  }

  /* Split head into 'a' and 'b' sublists */
  FrontBackSplit(head, &a, &b);

  /* Recursively sort the sublists */
  MergeSort(&a);
  MergeSort(&b);

  /* answer = merge the two sorted lists together */
  *headRef = SortedMerge(a, b);
}
 
/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
ListNode* SortedMerge(ListNode* a, ListNode* b) {
  ListNode* result = NULL;

  /* Base cases */
  if (a == NULL)
    return (b);
  else if (b == NULL)
    return (a);

  /* Pick either a or b, and recur */
  if (a->val <= b->val) {
    result = a;
    result->next = SortedMerge(a->next, b);
  }
  else {
    result = b;
    result->next = SortedMerge(a, b->next);
  }
  return (result);
}

void FrontBackSplit(ListNode* source,
                    ListNode** frontRef, ListNode** backRef) {
  ListNode* fast;
  ListNode* slow;
  slow = source;
  fast = source->next;

  /* Advance 'fast' two ListNodes, and advance 'slow' one ListNode */
  while (fast != NULL) {
    fast = fast->next;
    if (fast != NULL) {
      slow = slow->next;
      fast = fast->next;
    }
  }

  /* 'slow' is before the midpoint in the list, so split it in two
  at that point. */
  *frontRef = source;
  *backRef = slow->next;
  slow->next = NULL;
}

ListNode* Solution::sortList(ListNode* A) {
  if(!A) return A;
  ListNode *temp = A;
  MergeSort(&temp);
  return temp;
}
