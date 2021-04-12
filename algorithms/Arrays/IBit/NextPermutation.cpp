/**
https://www.interviewbit.com/problems/next-permutation/
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.
If such arrangement is not possible, it must be rearranged as the lowest possible order i.e., sorted in an ascending order.
Note:
1. The replacement must be in-place, do **not** allocate extra memory.
2. DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use of Library functions will disqualify your submission retroactively and will give you penalty points.
Input Format:
The first and the only argument of input has an array of integers, A.
Output Format:
Return an array of integers, representing the next permutation of the given array.
Constraints:
1 <= N <= 5e5
1 <= A[i] <= 1e9
Examples:
Input 1: A = [1, 2, 3]
Output 1: [1, 3, 2]
Input 2: A = [3, 2, 1]
Output 2: [1, 2, 3]
Input 3: A = [1, 1, 5]
Output 3: [1, 5, 1]
Input 4: A = [20, 50, 113]
Output 4: [20, 113, 50]
Hint:
It might help to write down the next permutation on paper to see how and when the sequence changes.
You’ll realize the following pattern :
The suffix which gets affected is in a descending order before the change.
A swap with the smaller element happens and then we reverse the affected suffix.
1 2 3 -> 1 3 2   // Suffix being just the 3. 
1 2 3 6 5 4  -> 1 2 4 3 5 6 // Suffix being 6 5 4 in this case. 
**/
void nextPermutation(vector<int> &num) {
  int len = num.size();
  int i,j;
  for(i = len - 2; i >= 0 ; i--)
    if(num[i] < num[i+1]) break;
  if (i == -1) {
    reverse(num.begin(), num.end());
    return;
  }
  for(j = len - 1; j > i; j--)
    if(num[j] > num[i]) break;
  swap(num[i], num[j]);
  reverse(num.begin() + i + 1, num.end());
  return;
}
