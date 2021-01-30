/**
Given a Binary Tree, print Left view of it.
Left view of a Binary Tree is set of nodes visible when tree is visited from Left side.
The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /   \    /    \
  4     5   6    7
   \
     8   
**/

vector<int> leftView(Node *root)
{
    vector<int> res;
    if(!root) return res;
   // Your code here
   map<int, int> m; 
   queue<Node *> q;
   q.push(root);
   q.push(nullptr);
   int i = 0;
   while(!q.empty()) {
       root = q.front();
       q.pop();
       
       if(!root) {
           if(!q.empty()) {
               i++;
               q.push(nullptr);
           }
       }
       else {
            if(m.find(i) == m.end()) {
                res.push_back(root->data);
                m[i] = root->data;
            }
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
       }
   }
   return res;
}
