/*
Link: https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.

Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Input:
First line of input contains number of testcases T.
For each testcase, first line of input contains number of nodes in the 
linked list and next line contains N elements of the linked list.
Output:
For each test, in a new line, print the sorted linked list.

Your Task:
For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.
Constraints:
1 <= T <= 100
1 <= N <= 105
Example:
Input:
2
5
3 5 2 4 1
3
9 15 0
Ouput:
1 2 3 4 5
0 9 15
Explanation:
Testcase 1: After sorting the given linked list, the resultant matrix will be 1->2->3->4->5.

This is a function problem.You only need to complete the function given below
Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/
Node *merge(Node *a, Node *b) { 
    if(!a) return b;
    if(!b) return a;

    Node *res = nullptr;
    if(a->data <= b->data) {
        res = a;
        res->next = merge(a->next, b);
    } else {
        res = b;
        res->next = merge(a, b->next);
    }
    return res;
}

Node* mergeSort(Node* head) {
    if(!head || !(head->next)) return head;
    
    Node *slow = head;
    Node *fast = head;
    while(fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *head2 = slow->next;
    if(slow) slow->next = nullptr;
    return merge(mergeSort(head), mergeSort(head2));
}
