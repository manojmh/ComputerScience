/**
https://www.interviewbit.com/problems/even-reverse/
Given a linked list A , reverse the order of all nodes at even positions.
Problem Constraints
1 <= Size of linked list <= 100000
Input Format
First and only argument is the head of the Linked-List A.
Output Format
Return the head of the new linked list.
Example Input
Input 1:
A = 1 -> 2 -> 3 -> 4
Input 2:
A = 1 -> 2 -> 3
Example Output
Output 1:
1 -> 4 -> 3 -> 2
Output 2:
1 -> 2 -> 3
Example Explanation
Explanation 1: Nodes are positions 2 and 4 have been swapped.
Explanation 2: No swapping neccassary here.
**/
ListNode *reverse(ListNode *head) {
  ListNode *prev = nullptr, *cur = head, *next = nullptr;
  while(cur) {
    //cout << cur->val << " ";
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}
ListNode* Solution::solve(ListNode* A) {
  if(!A) return A;
  ListNode *odd = new ListNode(0), *curo = odd;
  ListNode *even = new ListNode(0), *cure = even;
  ListNode *cur = A;
  int flag = true;
  while(cur) {
    //cout << cur->val << " ";
    if(flag) {
      //cout << cur->val << " ";
      flag = false;
      curo->next = cur;
      curo = curo->next;
      cur = cur->next;
      curo->next = nullptr;
    }
    else {
      //cout << cur->val << " ";
      flag = true;
      cure->next = cur;
      cure = cure->next;
      cur = cur->next;
      cure->next = nullptr;
    }
  }
  even->next = reverse(even->next);
  cur = new ListNode(0);
  curo = odd->next;
  cure = even->next;
  flag = true;
  while(curo && cure) {
    if(flag) {
      flag = false;
      cur->next = curo;
      curo = curo->next;
    }
    else {
      flag = true;
      cur->next = cure;
      cure = cure->next;
    }
    cur = cur->next;
  }
  if(curo)
    cur->next = curo;
  if(cure)
    cur->next = cure;
  return A;
}
