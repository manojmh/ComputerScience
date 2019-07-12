/*
Links: https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k/
https://www.geeksforgeeks.org/number-subarrays-product-less-k/

Hint: Sliding Window

Given an array of positive numbers, the task is to find the number of possible 
contiguous subarrays having product less than a given number K.
Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case consists of two lines. 
First line of each test case contains two integers N & K and the second 
line contains N space separated array elements.

Output:
For each test case, print the count of required subarrays in new line.
Constraints:
1<=T<=200
1<=N<=105
1<=K<=1015
1<=A[i]<=105

Example:
Input:
2
4 10
1 2 3 4
7 100
1 9 2 8 6 4 3
Output:
7
16
Explanation:
Input : A[]={1, 2,3,4} 
        K = 10
Output : 7
The contiguous subarrays are {1}, {2}, {3}, {4}
{1, 2}, {1, 2, 3} and {2, 3} whose count is 7.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    while(T--)
    {
        long long n, k;
        cin >> n >> k;
        long long a[n];
        for(long long i=0; i<n; i++)
            cin >> a[i];
        
        long long prod = 1;
        long long count = 0;
        
        for(long long start=0, end=0; end<n; end++)
        {
            prod *= a[end];
            while(start<end && prod >= k)
                prod /= a[start++];
            if(prod<k)
                count += end-start+1;
        }
        cout << count << endl;
    }
	return 0;
}
