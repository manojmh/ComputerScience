/**
https://www.interviewbit.com/problems/bst-iterator/
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest number in the BST, and so on.
Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
Try to optimize the additional space complexity apart from the amortized time complexity. 
**/
TreeNode *cur;
stack<TreeNode *> s; 
BSTIterator::BSTIterator(TreeNode *root) {
  if(!root) return;
  cur = nullptr;
  while(!s.empty()) s.pop();
  for(cur = root; cur; cur=cur->left) {
    s.push(cur);
  }       
}
/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
  return !s.empty();
}
/** @return the next smallest number */
int BSTIterator::next() {
  if(!s.empty()) {
    TreeNode *res = s.top();
    s.pop();
    if(res->right) {
      for(TreeNode *temp = res->right; temp; temp=temp->left)
        s.push(temp);
    }
    return res->val;
  }
  return 0;
}
