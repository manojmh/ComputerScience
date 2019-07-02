/*
Given an array of positive integers. The task is to print the maximum length of Bitonic subsequence. 
a subsequenceof array is called Bitonic if it is first increasing, then decreasing.

Input:
First line contains T test cases. First line of every test case consists of N , denoting number of elements in an array. Second line of every test consists of elements in array.

Output:
For each testcase, in a new line, print the length of longest bitonic sequence.

Constraints:
1<=T<=100
1<=N<=100
1<=Ai<=200

Example:
Input:
2
5
1 2 5 3 2
8
1 11 2 10 4 5 2 1
Output:
5
6
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
        int a[n], LIS[n], LDS[n];
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
            LIS[i] = LDS[i] = 1;
        }
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(a[i]>a[j] && LIS[i] < LIS[j]+1)
                {
                    LIS[i] = LIS[j] + 1;
                }
            }
        }
        for(int i=n-2; i>=0; i--)
        {
            for(int j=n-1; j>i; j--)
            {
                if(a[i]>a[j] && LDS[i] < LDS[j]+1)
                {
                    LDS[i] = LDS[j] + 1;
                }
            }
        }
        int max = INT_MIN;
        for(int i=0; i<n; i++)
            if(max < (LIS[i]+LDS[i]-1))
                max = LIS[i]+LDS[i]-1;
        cout << max <<endl;
        
    }
	return 0;
}
