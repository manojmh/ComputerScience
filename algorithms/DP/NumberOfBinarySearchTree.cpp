/*
Also known as:
Unique BST's
Catalan Number
Link: https://practice.geeksforgeeks.org/problems/unique-bsts/
Given an integer N, how many structurally unique binary search trees are there that store values 1...N?
Input:
First line of input contains T denoting the number of testcases. T testcases follow. 
Each testcase contains a single line of input containing N.
Ouput:
For each testcase, in a new line, print the answer.
Constraints:
1<=T<=15
1<=N<=11
Example:
Input:
2
2
3
Output:
2
5
Explanation:
Testcase1:
for N = 2, there are 2 unique BSTs
     1               2  
      \            /
       2         1
Testcase2:
for N = 3, there are 5 possible BSTs
  1              3        3        2      1
    \           /        /       /   \      \
     3        2         1       1     3      2
    /       /            \                     \
   2      1               2                     3
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    int res[12];
    memset(res, 0, sizeof(res));
    res[0] = 1;
    res[1] = 1;
    for(int i=2; i<=11; i++)
        for(int j=0; j<i; j++)
            res[i] += res[j] * res[i-j-1];
    while(T--)
    {
        int n;
        cin >> n;
        cout << res[n] << endl;
    }
    return 0;
}
