/**
https://www.interviewbit.com/problems/k-reverse-linked-list/
Given a singly linked list and an integer K, reverses the nodes of the
list K at a time and returns modified linked list.
NOTE : The length of the list is divisible by K 
Example :
Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,
You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5
Try to solve the problem using constant extra space.
**/
void reverse(ListNode **head) {
  ListNode *cur = (*head), *prev = nullptr, *next=nullptr;
  while(cur) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  (*head) = prev;
}
ListNode* Solution::reverseList(ListNode* head, int k) {
  if(!head || k==0 || k==1) return head;
  vector<ListNode *> heads;
  ListNode *cur = head;
  heads.push_back(head);
  int i = 1;
  while(cur) {
    if(i<k) {
      i++;
      cur = cur->next;
    }
    else {
      i = 1;
      if(cur->next)
        heads.push_back(cur->next);
      ListNode *next = cur->next;
      cur->next = nullptr;
      cur = next;
    }
  }
  for(int i=0; i<heads.size(); i++) {
    ListNode *head = heads[i];
    ListNode *cur = head;
    int j=1;
    while(cur) {
      j++;
      cur = cur->next;
    }
    if(j>k)
      reverse(&head);
    heads[i] = head;
    //cout << head->val << " ";
  }
  for(int i=0; i<heads.size()-1; i++) {
    ListNode *cur = heads[i];
    while(cur->next) {
      cur = cur->next;
    }
    cur->next = heads[i+1];
  }
  head = heads[0];
  //cout << endl;
  return head;
}

//Editorial
ListNode* Solution::reverseList(ListNode* A, int B) {
  ListNode *curr = A, *prev = NULL, *next = NULL;
  int cnt =0;
  while(cnt<B && curr) {
   next = curr->next;
   curr->next = prev;
   prev = curr;
   curr = next;
   cnt++;
  }
  if(next) {
   A->next = reverseList(next, B);
  }
  return prev;
}
