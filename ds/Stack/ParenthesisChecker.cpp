/*
Link : https://practice.geeksforgeeks.org/problems/parenthesis-checker/
Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”
Input:
The first line of input contains an integer T denoting the number of test cases.  
Each test case consists of a string of expression, in a separate line.
Output:
Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.
Constraints:
1 ≤ T ≤ 100
1 ≤ |s| ≤ 105
Example:
Input:
3
{([])}
()
([]
Output:
balanced
balanced
not balanced
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    while(T--)
    {
        string s;
        cin >> s;
        stack<char> st;
        for(int i=0; i<s.length(); i++)
        {
            switch(s[i])
            {
                case '[':
                case '{':
                case '(':
                    st.push(s[i]);
                break;
                
                case ']':
                case '}':
                case ')':
                    if(!st.empty() && s[i] == ']' && st.top() == '[') st.pop();
                    else if(!st.empty() && s[i] == '}' && st.top() == '{') st.pop();
                    else if(!st.empty() && s[i] == ')' && st.top() == '(') st.pop();
                    else {
                        cout << "not balanced" << endl;
                        goto end;
                    } 
                    break;
                default:
                    cout << "not balanced" << endl;
                    goto end;
                break;
            }
        }
        if(st.empty()) cout << "balanced" << endl;
        else cout << "not balanced" << endl;
        end:;
    }
	return 0;
}
