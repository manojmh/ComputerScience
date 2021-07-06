/**
https://www.interviewbit.com/old/problems/seats/
There is a row of seats. Assume that it contains N seats adjacent to each other.
There is a group of people who are already seated in that row randomly. i.e. some are sitting together & some are scattered.
An occupied seat is marked with a character 'x' and an unoccupied seat is marked with a dot ('.')
Now your target is to make the whole group sit together i.e. next to each other,
without having any vacant seat between them in such a way that the total number of hops or jumps to move them should be minimum.
Return minimum value % MOD where MOD = 10000003
Example
Here is the row having 15 seats represented by the String (0, 1, 2, 3, ......... , 14) -
. . . . x . . x x . . . x . .
Now to make them sit together one of approaches is -
. . . . . . x x x x . . . . .
Following are the steps to achieve this -
1 - Move the person sitting at 4th index to 6th index -  
    Number of jumps by him =   (6 - 4) = 2

2 - Bring the person sitting at 12th index to 9th index - 
    Number of jumps by him = (12 - 9) = 3

So now the total number of jumps made = 
    ( 2 + 3 ) % MOD = 
    5 which is the minimum possible jumps to make them seat together.

There are also other ways to make them sit together but the number of jumps will exceed 5 and that will not be minimum.

For example bring them all towards the starting of the row i.e. start placing them from index 0. 
In that case the total number of jumps will be 
    ( 4 + 6 + 6 + 9 )%MOD 
    = 25 which is very costly and not an optimized way to do this movement

Intution:
Think it this way: Suppose you have 1 gap, 5 people on left of it and 500 on right of it. How would you fill this gap?
To shift the 5 guys from left instead of shifting the 500 guys from other side, right?
That’s the whole theory behind median approach, the lesser ones move towards the larger ones to fill the gaps (median will always be toward the higher side).
So no need to find out median. For each individual gap, calculate the no. of people in its left and its right and add the ones which are minimum.
That can be done using two pointers:
**/
int Solution::seats(string A) {
  int n = A.length();
  int left=0, right=0;
  int i=0, j=n-1;
  int ans = 0;
  while(i<=j) {
    while(i<=j && A[i] == 'x') {
      left++;
      i++;
    }
    while(i<=j && A[j] == 'x') {
      right++;
      j--;
    }
    if(i<=j) {
      if(left<=right) {
        ans = (ans + left) % 10000003;
        i++;
      }
      else {
        ans = (ans + right) % 10000003;
        j--;
      }
    }
  }
  return ans;
}
