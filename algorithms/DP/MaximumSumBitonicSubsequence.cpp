/*
Given an array of integers A. A subsequence of A is called Bitonic if it is first increasing then decreasing.

Input:
The first line contains an integer T denoting the no of test cases. Each test case consist of two lines. The first line contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array A[].

Output:
For each test case in a new line print the max sum bitonic subsequence.

Constraints:
1<=T<=100
1<=N<=50
1<=A[]<=100

Example:
Input:
2
6
80 60 30 40 20 10
9
1 15 51 45 33 100 12 18 9

Output:
210
194

Explanation:
Testcase2:
Input : A[] = {1, 15, 51, 45, 33, 100, 12, 18, 9}
Output : 194
 Bi-tonic Sub-sequence are :
{1, 51, 9} 
{1, 50, 100, 18, 9}
{1, 15, 51, 100, 18, 9}
{1, 15, 45, 100, 12, 9}
{1, 15, 45, 100, 18, 9} .. so on           
Maximum sum Bi-tonic sub-sequence is 1 + 15 + 51 + 100 + 18 + 9 = 194 
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
            LIS[i] = a[i];
            LDS[i] = a[i];
        }
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(a[j] < a[i] && LIS[i] < LIS[j]+a[i])
                    LIS[i] = LIS[j] + a[i];
            }
        }
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=n-1; j>i; j--)
            {
                if(a[j] < a[i] && LDS[i] < LDS[j]+a[i])
                    LDS[i] = LDS[j] + a[i];
            }
        }
        int max_sum = INT_MIN;
        for(int i=0; i<n; i++)
            max_sum = max(max_sum, LIS[i]+LDS[i]-a[i]);
        cout << max_sum << endl;
    }
	return 0;
}
