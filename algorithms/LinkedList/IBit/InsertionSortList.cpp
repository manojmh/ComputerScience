/**
https://www.interviewbit.com/problems/insertion-sort-list/
Sort a linked list using insertion sort.
We have explained Insertion Sort at Slide 7 of Arrays
Insertion Sort Wiki has some details on Insertion Sort as well.
Example :
Input : 1 -> 3 -> 2
Return 1 -> 2 -> 3
**/
void insSort(ListNode** newList, ListNode* newNode){
  if(*newList==NULL || newNode->val <= (*newList)->val){
    newNode->next = *newList;
    *newList = newNode;
  }
  else{
    ListNode* curr = *newList;
    while(curr->next && curr->next->val < newNode->val){
      curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
  }
}
ListNode* Solution::insertionSortList(ListNode* A) {
  ListNode* temp = A;
  ListNode* newList = NULL;
  ListNode* next;
  while(temp){
    next = temp->next;
    insSort(&newList, temp);
    temp = next;
  }
  return newList;
}
