/*
Link: https://practice.geeksforgeeks.org/problems/mirror-tree/1
Given a Binary Tree, convert it into its mirror.
MirrorTree1            

Input Format:
The first line of input contains T denoting the number of testcases. 
T testcases follow. Each testcase contains two lines of input. 
The first line contains number of edges. 
The second line contains relation between nodes.

Output Format:
For each testcase, in a new line, print inorder traversal of mirror tree.

Your Task:
You don't have to take any input. Just complete the function mirror() that takes node as paramter. The printing is done by the driver code.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
2 1 3
30 10 60 20 40

Explanation:
Testcase1: The tree is
      1         (mirror)     1
    /   \         =>       /   \
   3     2                2     3
The inorder of mirror is 2 1 3
Testcase2: The tree is
                           10                            10
                        /     \           (mirror)      /  \
                      20      30            =>        30    20
                    /   \                                  /  \
                  40     60                              60    40
The inroder traversal of mirror is 30 10 60 20 40.
*/

/*This is a function problem.You only need to complete the function given below*/
//function Template for C++
/* A binary tree node has data, pointer to left child
   and a pointer to right child /
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
/* Should convert tree to its mirror */

void mirror(Node* node) 
{
    if(!node) return;
     
    if(node->left) mirror(node->left);
    if(node->right) mirror(node->right);
    swap(node->left, node->right);
}
