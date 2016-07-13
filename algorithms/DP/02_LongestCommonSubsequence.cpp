/**
 * Date 14/07/2016
 * @author Manoj Hanamshet
 *
 * Program to find the longest common subsequence in 2 strings
 *
 * Time complexity - O(mn)
 *
 * References -
 * https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/LongestCommonSubsequence.java
 * http://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence/
 */

#include <iostream>
using namespace std;

int max(int a, int b)
{
    return (a>b?a:b);
}

//Function to find longestCommonSubsequence
int lcs(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    int T[len1+1][len2+1];
    int retMax = 0;

    for(int i=0; i<=len1; i++)
    {
        for(int j=0; j<=len2; j++)
        {
            if(i==0 || j==0)
                T[i][j] = 0;
            else if(str1[i-1] == str2[j-1])
                T[i][j] = T[i-1][j-1] + 1;
            else
                T[i][j] = max(T[i-1][j], T[i][j-1]);
        }
    }
    return T[len1][len2];
}

int main()
{
    string str1 = "abcdaf";
    string str2 = "acbcf";
    
    std::cout << lcs(str1, str2) << endl;
}
