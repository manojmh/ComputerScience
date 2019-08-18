/*
Link: https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits/0/?track=sp-arrays-and-searching
Given a keypad as shown in diagram, and an N digit number. List all words which are possible by pressing these numbers.
Input:
The first line of input contains an integer T denoting the number of test cases.
T testcases follow. Each testcase contains two lines of input. 
The first line of each test case is N, N is the number of digits. 
The second line of each test case contains D[i], N number of digits.
Output:
Print all possible words from phone digits with single space in lower case.
Constraints:
1 <= T <= 10
1 <= N <= 10
2 <=  D[i] <= 9
Example:
Input:
1
3
2 3 4
Output:
adg adh adi aeg aeh aei afg afh afi bdg bdh bdi beg beh bei bfg bfh bfi cdg cdh cdi ceg ceh cei cfg cfh cfi
*/
#include<bits/stdc++.h>
using namespace std;
const string str[] = {"", "", "abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};

void permute(int a[], int n, string s, int i) {
  if(i==n) {
    cout << s << " ";
    return;
  } 
  for(int j=0; j<str[a[i]].size(); j++) {
    s.push_back(str[a[i]][j]); //add char to string
    permute(a,n,s,i+1);
    s.pop_back(); //remove char from string(backtrack)
  }
}

int main()
{
  int T = 0;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
      cin >> a[i];
    }
    string s;
    permute(a,n,s,0);
    cout << endl;
  }
  return 0;
}
