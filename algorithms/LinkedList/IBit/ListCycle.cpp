/**
https://www.interviewbit.com/problems/list-cycle/
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Try solving it using constant additional space.
Example :
Input : 
                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 
**/
ListNode* Solution::detectCycle(ListNode* A) {
  ListNode *slow = A;
  ListNode *fast = A;
  while(slow && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast)
        break;
  }
  if(slow == fast) {
    slow = A;
    while(slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
  return nullptr;
}
