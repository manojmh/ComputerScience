#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  Node(int d, Node *l, Node *r, int h)
  : data(d), left(l), right(r), height(h) {}
  int data;
  Node *left, *right;
  int height;
};

int height(Node *root) {
  if(!root) return 0;
  return root->height;
}

int getBalance(Node *root) {
  if(!root) return 0;
  return height(root->left) - height(root->right);
}

Node *leftRotate(Node *root) {
  Node *t = root->right;
  root->right = t->left;
  t->left = root;

  root->height = 1+ max(height(root->left), height(root->right));
  t->height = 1 + max(height(t->left), height(t->right));

  return t;
}

Node *rightRotate(Node *root) {
  Node *t = root->left;
  root->left = t->right;
  t->right = root;

  root->height = 1 + max(height(root->left), height(root->right));
  t->height = 1 + max(height(t->left), height(t->right));

  return t;
}

Node *getMinValue(Node *root) {
  if(!root) return root;
  while(root->left)
    root = root->left;
  return root;
}

Node *insertKey(Node *root, int key) {
  if(!root) return new Node(key, nullptr, nullptr, 1);
  if(key < root->data)
    root->left = insertKey(root->left, key);
  else if(key > root->data)
    root->right = insertKey(root->right, key);
  else
    return root;

  root->height = 1 + max(height(root->left), height(root->right));

  int balance = getBalance(root);
  //Left left case
  if(balance > 1 && key < root->left->data)
    return rightRotate(root);
  //Right right case
  if(balance < -1 && key > root->right->data)
    return leftRotate(root);
  //Left right case
  if(balance > 1 && key > root->left->data) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  //Right left case
  if(balance < -1 && key < root->right->data) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}

Node *deleteKey(Node *root, int key) {
  if(!root) return root;
  if(key < root->data)
    root->left = deleteKey(root->left, key);
  else if(key > root->data)
    root->right = deleteKey(root->right, key);
  else {
    if(root->left == nullptr || root->right == nullptr) {
      Node *cur = root->left ? root->left : root->right;
      if(!cur) {
        cur = root;
        root = nullptr;
      }
      else {
        *root = *cur;
      }
      delete(cur);
    }
    else {
      Node *succ = getMinValue(root->right);
      root->data = succ->data;
      root->right = deleteKey(root->right, succ->data);
    }
  }

  if(!root) return root;
  root->height = 1 + max(height(root->left), height(root->right));

  int balance = getBalance(root);
  //Left left case
  if(balance > 1 && getBalance(root->left) >=0 )
    return rightRotate(root);
  //Left right case
  if(balance > 1 && getBalance(root->left) < 0 ) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  //Right right case
  if(balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);
  //Right left case
  if(balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}

Node *deleteTree(Node *root) {
  if(!root) return root;
  root->left = deleteTree(root->left);
  root->right = deleteTree(root->right);
  cout << "\ndeleting " << root->data << endl;
  delete root;
  return nullptr;
}

void levelOrder(Node *root) {
  if(!root) return;
  queue<Node *> q;
  q.push(root);
  q.push(nullptr);
  while(!q.empty()) {
    Node *t = q.front();
    q.pop();

    if(!t) {
      cout << endl;
      if(q.empty())
        break; 
      q.push(nullptr);
    }
    else {
      cout << t->data << " ";

      if(t->left)
        q.push(t->left);
      if(t->right)
        q.push(t->right);
    }
  }
}

void preOrder(Node * root) {
  if(!root) return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

// Driver Code 
int main()  
{  
  Node *root = nullptr;  

  /* Constructing tree given in 
  the above figure */
  root = insertKey(root, 9);  
  root = insertKey(root, 5);  
  root = insertKey(root, 10);  
  root = insertKey(root, 0);  
  root = insertKey(root, 6);  
  root = insertKey(root, 11);  
  root = insertKey(root, -1);  
  root = insertKey(root, 1);  
  root = insertKey(root, 2);  

  /* The constructed AVL Tree would be  
       9  
      / \  
     1  10  
    / \   \  
   0   5   11  
  /   / \  
  -1   2   6  
  */

  cout << "Preorder traversal of the "
          "constructed AVL tree is \n";  
  preOrder(root);  

  root = deleteKey(root, 10);  

  /* The AVL Tree after deletion of 10  
       1  
      / \  
     0   9  
    /   / \  
  -1   5   11  
      / \  
     2   6  
  */

  cout << "\nPreorder traversal after"
       << " deletion of 10 \n";  
  preOrder(root);
  deleteTree(root);

  return 0;  
}
