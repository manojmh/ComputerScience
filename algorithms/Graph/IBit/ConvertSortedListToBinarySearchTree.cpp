/**
https://www.interviewbit.com/old/problems/convert-sorted-list-to-binary-search-tree/
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
A height balanced BST : a height-balanced binary tree is defined as a binary tree
in which the depth of the two subtrees of every node never differ by more than 1. 
Example :
Given A : 1 -> 2 -> 3
A height balanced BST  :
    2
  /   \
 1     3
**/
int countLNodes(ListNode *head) { 
  int count = 0; 
  ListNode *temp = head; 
  while(temp) { 
    temp = temp->next; 
    count++; 
  } 
  return count; 
}
TreeNode* sortedListToBSTRecur(ListNode **head_ref, int n)  {
  /* Base Case */
  if (n <= 0) 
    return NULL; 

  /* Recursively construct the left subtree */
  TreeNode *left = sortedListToBSTRecur(head_ref, n/2); 

  /* Allocate memory for root, and 
  link the above constructed left 
  subtree with root */
  TreeNode *root = new TreeNode((*head_ref)->val); 
  root->left = left; 

  /* Change head pointer of Linked List
  for parent recursive calls */
  *head_ref = (*head_ref)->next; 

  /* Recursively construct the right 
    subtree and link it with root 
    The number of nodes in right subtree
    is total nodes - nodes in 
    left subtree - 1 (for root) which is n-n/2-1*/
  root->right = sortedListToBSTRecur(head_ref, n - n / 2 - 1); 
  return root;
}
TreeNode* Solution::sortedListToBST(ListNode *head) {
    /*Count the number of nodes in Linked List */
    int n = countLNodes(head); 
      /* Construct BST */
    return sortedListToBSTRecur(&head, n); 
}
