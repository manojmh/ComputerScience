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

Theory:
Looking closely at the chessboard we can see that in addition to the 1 x 1 squares, there can be a combination of 2 x 2, 3 x 3, 4 x 4, 5 x 5, 6 x 6, 7 x 7, and 8 x 8 squares too. To get the total number of squares we need to find all the squares formed.
1 x 1: 8 * 8 = 64 squares.
2 x 2: 7 * 7 = 49 squares.
3 x 3: 6 * 6 = 36 squares.
4 x 4: 5 * 5 = 25 squares.
5 x 5: 4 * 4 = 16 squares.
6 x 6: 3 * 3 = 9 squares.
7 x 7: 2 * 2 = 4 squares.
8 x 8: 1 * 1 = 1 square.
Therefore, we have in all = 64 + 49 + 36 + 25 + 16 + 9 + 4 + 1 = 204 squares in a chessboard.
Input: n = 2
Output: 5 (4 squares of 1 unit + 1 square of 2 units)

Input: n = 3
Output: 14 (9 squares of 1 unit + 4 square of 2 units + 1 square of 1 unit)
For a grid of size n*n the total number of squares formed are:
1^2 + 2^2 + 3^2 + ... + n^2 = n(n+1)(2n+1) / 6 
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
