/*
Link: https://practice.geeksforgeeks.org/problems/maximize-toys/
Given an array consisting cost of toys. Given an integer K depicting the amount with you. 
Maximise the number of toys you can have with K amount.
Input:
The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the number of toys and an integer K depicting the value of K.
Next line is followed by the cost of toys.
Output:
Print the maximum toys in separate line.
Constraints:
1 ≤ T ≤ 30
1 ≤ N ≤ 1000
1 ≤ K ≤ 10000
1 ≤ A[i] ≤ 10000
Example:
Input
1
7 50
1 12 5 111 200 1000 10
Output
4
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    while(T--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int i=0; i<n; i++)
            cin >> a[i];
        sort(a, a+n);
        
        int sum = 0, count = 0;
        for(int i=0; i<n; i++)
        {
            sum += a[i];
            if(sum <= k)
                count++;
            else
                break;
        }
        cout << count << endl;
    }
	return 0;
}
