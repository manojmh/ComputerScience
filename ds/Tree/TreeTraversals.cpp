/*
Links:
https://practice.geeksforgeeks.org/problems/inorder-traversal/1
https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
https://practice.geeksforgeeks.org/problems/preorder-traversal/1/
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

void preOrderRec(Node *root) {
  if(!root) return;

  cout << root->data << " ";
  if(root->left) preOrderRec(root->left);
  if(root->right) preOrderRec(root->right);
}

void inOrderRec(Node *root) {
  if(!root) return;
  
  if(root->left) inOrderRec(root->left);
  cout << root->data << " ";
  if(root->right) inOrderRec(root->right);
}

void postOrderRec(Node *root) {
  if(!root) return;

  if(root->left) postOrderRec(root->left);
  if(root->right) postOrderRec(root->right);
  cout << root->data << " ";
}

void preOrderIter(Node* root) {
  if(!root) return;

  stack<Node *> st;
  st.push(root);

  while(!st.empty()) {
    root = st.top();
    st.pop();

    cout << root->data << " ";
    //right first and then left
    if(root->right) st.push(root->right); 
    if(root->left) st.push(root->left);
  }
}

void inOrderIter(Node* root) {
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

void postOrderIter(Node* root)
{
  stack<Node *> st1, st2;
  st1.push(root);

  while(!st1.empty()) {
    root = st1.top();
    st1.pop();

    if(root->left) st1.push(root->left);
    if(root->right) st1.push(root->right);
    st2.push(root);
  }

  while(!st2.empty()) {
    root = st2.top();
    st2.pop();
    cout << root->data << " ";
  }
}

void preOrder(Node *root) {
  preOrderRec(root);
  preOrderIter(root);
}

void inOrder(Node *root) {
  inOrderRec(root);
  inOrderIter(root);
}

void postOrder(Node *root) {
  postOrderRec(root);
  postOrderIter(root);
}
