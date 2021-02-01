/**
Lowest Common Ancestor in Binary Tree and Binary Search Tree
**/

//Lowest Common Ancestor in Binary Tree
Node* lcaBT(Node* root ,int n1 ,int n2 )
{
    if(!root) return nullptr;
    if(root->data == n1 || root->data == n2) return root;

    Node *left = lcaBT(root->left, n1, n2);
    Node *right = lcaBT(root->right, n1, n2);
    
    if(left == nullptr && right == nullptr) return nullptr;
    if(left != nullptr && right != nullptr) return root;
    
    return left ? left : right;
}

//Lowest Common Ancestor in Binary Search Tree
Node* lcaBST(Node *root, int n1, int n2)
{
    if(!root) return root;
    if(root->data > max(n1, n2))
        return lcaBST(root->left, n1, n2);
    if(root->data < min(n1, n2))
        return lcaBST(root->right, n1, n2);
    return root;
}
