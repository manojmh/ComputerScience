/**
https://www.geeksforgeeks.org/segment-tree-efficient-implementation/
1. The picture makes it clear that the leaf nodes are stored at i+n, so we can clearly insert all leaf nodes directly.
2. The next step is to build the tree and it takes O(n) time. 
The parent always has its less index than its children, so we just process all the nodes in decreasing order, calculating the value of the parent node.
If the code inside the build function to calculate parents seems confusing, then you can see this code. It is equivalent to that inside the build function. 
  tree[i]=tree[2*i]+tree[2*i+1]
3. Updating a value at any position is also simple and the time taken will be proportional to the height of the tree.
We only update values in the parents of the given node which is being changed.
So to get the parent, we just go up to the parent node, which is p/2 or p>>1, for node p. p^1 turns (2*i) to (2*i + 1) and vice versa to get the second child of p.
4. Computing the sum also works in O(log(n)) time. If we work through an interval of [3,11), we need to calculate only for nodes 19,26,12, and 5 in that order.
The idea behind the query function is whether we should include an element in the sum or whether we should include its parent.
Let’s look at the image once again for proper understanding. Consider that L is the left border of an interval and R is the right border of the interval [L,R).
It is clear from the image that if L is odd, then it means that it is the right child of its parent and our interval includes only L and not the parent.
So we will simply include this node to sum and move to the parent of its next node by doing L = (L+1)/2.
Now, if L is even, then it is the left child of its parent and the interval includes its parent also unless the right borders interfere.
Similar conditions are applied to the right border also for faster computation. We will stop this iteration once the left and right borders meet.
The theoretical time complexities of both previous implementation and this implementation is the same, but practically, it is found to be much more efficient
as there are no recursive calls. We simply iterate over the elements that we need. Also, this is very easy to implement.

Time Complexities:
Tree Construction: O( n )
Query in Range: O( Log n )
Updating an element: O( Log n ).

Output:
index: 0  1  2  3 4   5 6 7 8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 
value: 0 78 68 10 26 42 3 7 11 15 19 23 1   2  3  4  5  6  7  8  9 10 11 12 
l15
r21
r5
39
**/
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n;
int tree[2 * N];
void build( int arr[]) {
	// insert leaf nodes in tree
	for (int i=0; i<n; i++)
		tree[n+i] = arr[i];
	
	// build the tree by calculating parents
	for (int i = n - 1; i > 0; --i)	
		tree[i] = tree[i<<1] + tree[i<<1 | 1];
}
void updateTreeNode(int p, int value) {
  // set value at position p
  tree[p+n] = value;
  p = p+n;

  // move upward and update parents
  for(int i=p; i>1; i/=2)
    tree[i/2] = tree[i] + tree[i^1];
  //Ediotiral way
  //for (int i=p; i > 1; i >>= 1)
    //tree[i>>1] = tree[i] + tree[i^1];
}
int query(int l, int r) {
  int res = 0;
  // loop to find the sum in the range
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += tree[l++];
    if (r&1) res += tree[--r];
  }
  return res;
}
// driver program to test the above function
int main() {
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	n = sizeof(a)/sizeof(a[0]);
	// build tree
	build(a);
  for(int i=0; i<2*n; i++)
    cout << i << " ";
  cout << endl;
	for (int i = 0; i <2*n; i++)	
		cout << tree[i] << " ";
  cout << endl;
	//print the sum in range(3,9) index-based
	cout << query(3, 9)<<endl;
	return 0;
}
