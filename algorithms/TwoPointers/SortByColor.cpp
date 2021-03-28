/** Facebook Microsoft
https://www.interviewbit.com/problems/sort-by-color/
Given an array with n objects colored red, white or blue,
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Note: Using library sort function is not allowed.
Example :
Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]
**/
void Solution::sortColors(vector<int> &A) {
  int zeros = 0;
  int ones = 0;
  int twos = 0;
  for(auto a:A) {
    if(a==0) zeros++;
    else if(a==1) ones++;
    else if(a==2) twos++;
  }
  int i=0;
  while(zeros--) A[i++] = 0;
  while(ones--) A[i++] = 1;
  while(twos--) A[i++] = 2;
}
