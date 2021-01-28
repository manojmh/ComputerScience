/*
Link:https://practice.geeksforgeeks.org/problems/maximum-height-of-the-staircase/
Given N number of square blocks. The height of each square block is 1. The task is to create a  staircase of max height using these blocks.
Note: The first stair would require only one block, the second stair would require two blocks and so on.
Input:
The first line of the input contains T i.e number of test cases. Each line of the test case contains a number  N i.e number of blocks. 
Output:
Each new line of the output contains only one single integer i.e Maximum height of staircase.
Constraints:
1<=T<=100
1<=N<=10^8
Example:
Input:
3
10
12
16
Output:
4
4
5
Explanation:
Test Case 1: the max height of the staircase that can be made from  12  blocks is 4. (A staircase of height 4 means sequence of 1,2,3,4 blocks to create a valid staircase.)
Theory:
You know that for n steps, you need (n * (n + 1))/2 blocks. You want know, if given B blocks, how many steps you can create.
So you have:
(n * (n + 1))/2 = B
(n^2 + n)/2 = B
n^2 + n = 2B
n^2 + n - 2B = 0
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        cout << (int)(sqrt(2.0 * n + 0.25) - 0.5) << endl;
    }
	return 0;
}
