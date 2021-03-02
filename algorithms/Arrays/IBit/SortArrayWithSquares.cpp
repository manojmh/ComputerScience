/** VMWare
Problem Description
Given a sorted array A containing N integers both positive and negative.
You need to create another array containing the squares of all the elements in A and return it in non-decreasing order.
Try to this in O(N) time.
Problem Constraints
1 <= N <= 105.
-103 <= A[i] <= 103
Input Format
First and only argument is an integer array A.
Output Format
Return a integer array as described in the problem above.
Example Input
Input 1: A = [-6, -3, -1, 2, 4, 5]
Input 2: A = [-5, -4, -2, 0, 1]
Example Output
Output 1: [1, 4, 9, 16, 25, 36]
Output 2: [0, 1, 4, 16, 25]
**/

vector<int> Solution::solve(vector<int> &A) {
  int idx = 0;
  vector<int> res(A.size(), 0);
  //Find the 1st index with sign change
  for(int i=0; i<A.size(); i++) {
    if(A[i] >= 0) {
      idx = i;
      break;
    }
  }
  //Pick element from left or right based on non decreasing order
  int k = 0;
  int left = idx-1;
  int right = idx;
  while(left >= 0 && right < A.size()) {
    if(A[left] * -1 < A[right]) {
      res[k] = A[left] * A[left];
      left--;
    }
    else {
      res[k] = A[right] * A[right];
      right++;
    }
    k++;
  }
  //Process remaining elements on the left side
  while(left>=0) {
    res[k++] = A[left] * A[left];
    left--;
  }
  //Process remaining elements on the right side
  while(right < A.size()) {
    res[k++] = A[right] * A[right];
    right++;
  }
  return res;
}
