/**
 * Date 22/07/2016
 * @author Manoj Hanamshet
 *
 * Given a string find longest palindromic subsequence in this string.
 *
 * Time complexity - O(n2)
 * Space complexity - O(n2)
 *
 * Youtube link - https://youtu.be/_nCsPn7_OgI
 *
 * References
 * http://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/
 * https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/LongestPalindromicSubsequence.java
 */

#include <iostream>
using namespace std;

//LongestPalindromicSubsequence
int lps(string s)
{
    int len = s.length();
    int T[len][len];
    
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            if(i==j)
                //max length of Palindromic Subsequence using 1 char is 1
                T[i][j] = 1;
            else
                T[i][j] = 0;
        }
    }
    
    for(int l=2; l<=len; l++)
    {
        for(int i=0; i<len-l+1; i++)
        {
            int j = i+l-1; //to choose chars between i to j
            if(l==2 && s[i]==s[j])
                T[i][j] = 2;
            else if(s[i]==s[j])
                //diagonal + 2
                T[i][j] = T[i+1][j-1] + 2;
            else
                //max of left and bottom element to the current item in T[len][len]
                T[i][j] = T[i][j-1] > T[i+1][j] ? T[i][j-1] : T[i+1][j];
        }
    }
    
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
            cout << T[i][j] << " ";
        cout << endl;
    }
    return T[0][len-1];
}

int main() 
{
    cout << "Longest Palindromic Subsequence for string agbdba is : "<< lps("agbdba");
    return 0;
}
