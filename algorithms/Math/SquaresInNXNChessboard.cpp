/*
Link: https://practice.geeksforgeeks.org/problems/squares-in-nn-chessboard/
Link: https://www.quora.com/How-many-squares-are-there-in-a-chessboard
Find total number of Squares in a N*N cheesboard.
Input:
The first line contains an integer T, depicting total number of test cases.
Then following T lines contains an integer N that is the side of the chessboard.
Output:
Each seperate line showing the maximum number of squares possible.
Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100
Example:
Input:
2
1
2
Output:
1
5
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
        cout << (n*(n+1)*(2*n+1))/6 << endl;
    }
	return 0;
}
