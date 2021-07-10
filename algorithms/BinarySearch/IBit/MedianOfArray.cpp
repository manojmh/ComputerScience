/**
https://www.interviewbit.com/old/problems/median-of-array/
There are two sorted arrays A and B of size m and n respectively.
Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).
The overall run time complexity should be O(log (m+n)).
Sample Input
A : [1 4 5]
B : [2 3]
Sample Output : 3
NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element.
For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5 
**/
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
  if(A.size() > B.size()) return findMedianSortedArrays(B, A);
  int x = A.size();
  int y = B.size();
  int low = 0, hi = x;
  while(low <= hi){
    int partitionX = (low + hi)/2;
    int partitionY = (x+y+1)/2 - partitionX; 
    int maxLeftX = (partitionX == 0)? INT_MIN :  A[partitionX-1];
    int minRightX = (partitionX == x)? INT_MAX :  A[partitionX];
    int maxLeftY = (partitionY == 0)? INT_MIN :  B[partitionY-1];
    int minRightY = (partitionY == y)? INT_MAX :  B[partitionY];
    if(maxLeftX <= minRightY && maxLeftY <= minRightX){
      if((x+y) % 2 == 0)
        return ((double) max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
      else
        return (double) max(maxLeftX, maxLeftY);
    }
    else if(maxLeftX > minRightY)
      hi = partitionX-1; 
    else
      low = partitionX+1;
  }   
}
