/*
Links:
https://practice.geeksforgeeks.org/problems/inorder-traversal/1
https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
struct Node
{
  int data;
  struct Node* left;
  struct Node* right;
  Node(int x){
    data = x;
    left = right = NULL;
  }
}; */

void inOrderRec(Node *root) {
  if(!root) return;
  
  if(root->left) inOrderRec(root->left);
  cout << root->data << " ";
  if(root->right) inOrderRec(root->right);
}

void inOrderIter(Node* root)
{
  if(!root) return;

  stack<Node *> st;
  Node *cur = root;

  while(cur || !st.empty()) {
    while(cur) {
        st.push(cur);
        cur = cur->left;
    }

    cur = st.top();
    st.pop();

    cout << cur->data << " ";
    cur=cur->right;
  }
}

void inOrder(Node *root) {
  inOrderRec(root);
  inOrderIter(root);
}
