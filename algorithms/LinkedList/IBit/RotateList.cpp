/**
https://www.interviewbit.com/problems/rotate-list/
Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
**/
ListNode* Solution::rotateRight(ListNode* head, int k) {
  if(!head || head->next == nullptr || k==0) return head;
    int count = 0;
    ListNode *cur = head;
    while(cur) {
      count++;
      cur = cur->next;
    }
    if(k>count)
    k = k%count;
    //cout << k;
    if(k==0 || k==count) return head;
    cur = head;
    count = count - k - 1;
    while((count > 0) && cur) {
      count--;
      cur = cur->next;
    }
    if(count == 0) 
    {
      //cout << cur->val << endl;
      ListNode *temp = head;
      head = cur->next;
      cur->next = nullptr;
      cur = head;
      while(cur && cur->next) cur = cur->next;
      if (cur)
        cur->next = temp;
    }
    return head;
}
//Editorial
ListNode *rotateRight(ListNode *head, int k) {
  if (head == NULL || head->next == NULL) return head;
  ListNode* dummy = new ListNode(0);
  dummy->next = head;
  ListNode *fast = dummy, *slow = dummy;
  int sizeOfList = 0; 
  while (fast->next != NULL) {
    fast = fast->next;
    sizeOfList++;
  }
  int firstNodePos = sizeOfList - (k % sizeOfList);
  for (int i = 0; i < firstNodePos; i++) {
    slow = slow->next;
  }
  fast->next = dummy->next;
  dummy->next = slow->next; 
  slow->next = NULL;
  return dummy->next;
}
