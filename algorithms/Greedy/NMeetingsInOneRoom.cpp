/*
N meetings in one room
Link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/
There is one meeting room in a firm. 
There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room?
Input:
The first line of input consists number of the test cases. The description of T test cases is as follows:
The first line consists of the size of the array, second line has the array containing
the starting time of all the meetings each separated by a space, i.e., S [ i ].
And the third line has the array containing the finishing time of all the meetings each separated by a space, i.e., F [ i ].
Output:
In each separate line print the order in which the meetings take place separated by a space.
Constraints:
1 ≤ T ≤ 70
1 ≤ N ≤ 100
1 ≤ S[ i ], F[ i ] ≤ 100000
Example:
Input:
2
6
1 3 0 5 8 5
2 4 6 7 9 9
8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252  
Output:
1 2 4 5
6 7 1
Explanation:
Testcase 1: Four meetings can held with given start and end timings.
*/

#include<bits/stdc++.h>
using namespace std;

struct act
{
    int i;
    int start;
    int end;
    bool operator<(const act &b) const
        {   
            return this->end < b.end;
        }  
};

int main()
{
    int T = 0;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        act a[n];
        for(int i=0; i<n; i++)
        {
            a[i].i = i+1;
            cin >> a[i].start;
        }
        for(int i=0; i<n; i++)
            cin >> a[i].end;
        sort(a, a+n);
        
        vector<int> v;
        v.push_back(a[0].i);
        int i=0; // activity one is always selected
        for(int j=1; j<n; j++){
            if(a[j].start >= a[i].end)
            {
                v.push_back(a[j].i);
                i=j;
            }
        }
        for(auto const &i : v)
            cout << i << " ";
        cout << endl;
    }
	return 0;
}
