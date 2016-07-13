/**
 * Date 14/07/2016
 * @author Manoj Hanamshet
 *
 * 0/1 Knapsack Problem - Given items of certain weights/values and maximum allowed weight
 * how to pick items to pick items from this set to maximize sum of value of items such that
 * sum of weights is less than or equal to maximum allowed weight.
 *
 * Time complexity - O(W*total items)
 *
 * Youtube link
 * Topdown DP - https://youtu.be/149WSzQ4E1g
 * Bottomup DP - https://youtu.be/8LusJS5-AGo
 *
 * References -
 * https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/Knapsack01.java
 * http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/
 * https://en.wikipedia.org/wiki/Knapsack_problem
 */

#include <iostream>
using namespace std;

int max(int a, int b)
{
    return (a>b?a:b);
}

int Knapsack(int v[], int w[], int len, int maxWt)
{
    int T[len+1][maxWt+1];
    for(int i=0; i<=len; i++)
    {
        for(int j=0; j<=maxWt; j++)
        {
            //Initialize 0th row and 0th column to 0;
            if(i==0 || j==0)
            {
                T[i][j] = 0;
                continue;
            }
            if(w[i-1] > j)
            {
                //If weight of an item is greater than max weight then copy previous row val
                T[i][j] = T[i-1][j];
            }
            else
            {
                //If weight is less than maxWeight then check for the max of previous value or current value + previous weight's value
                T[i][j] = max(v[i-1]+T[i-1][j-w[i-1]], T[i-1][j]);
            }
        }
    }
    return T[len][maxWt];
}

int main()
{

    int w1[] = {1,3,4,5};
    int v1[] = {1,4,5,7};
    cout << Knapsack(v1, w1, sizeof(w1)/sizeof(w1[0]), 7) << endl;

    int v2[] = {22, 20, 15, 30, 24, 54, 21, 32, 18, 25};
    int w2[] = {4, 2, 3, 5, 5, 6, 9, 7, 8, 10};
    cout << Knapsack(v2, w2, sizeof(w2)/sizeof(w2[0]), 30) << endl;

    return 0;
}
