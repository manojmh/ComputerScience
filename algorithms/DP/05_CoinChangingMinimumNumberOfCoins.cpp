/**
 * Date 16/07/2016
 * @author Manoj Hanamshet
 *
 * Given a total and coins of certain denomination with infinite supply, what is the minimum number
 * of coins it takes to form this total.
 *
 * Time complexity - O(coins.size * total)
 * Space complexity - O(coins.size * total)
 *
 * Youtube video -
 * Bottom up DP - https://youtu.be/Y0ZqKpToTic
 */

#include <iostream>
#include <climits>
using namespace std;
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

void printAllCoins(int R[], int coins[], int total)
{
	if(R[total] == -1)
		cout << "Not possible to get total = " << total;
	else
	{
		int start = total;
		while(start != 0)
		{
			cout << coins[R[start]] << " ";
			start -= coins[R[start]];
		}
		cout << endl;
	}
}

int coinChanging(int coins[], int n, int total)
{
	int T[total+1];
	int R[total+1];
	T[0] = 0;
	for(int i=1; i<=total; i++)
	{
		T[i] = 10000; //infinity
		R[i] = -1;
	}
	
	for(int j=0; j<n; j++)
	{
		for(int i=1; i<=total; i++)
		{
			if(i >= coins[j])
			{
				if(T[i-coins[j]]+1 < T[i])
				{
					T[i] = T[i-coins[j]] + 1;
					R[i] = j;
				}
			}
		}
	}
	printAllCoins(R, coins, total);
	return T[total];
}

int main()
{
	int coins[] = {7, 2, 3, 6};
	cout << coinChanging(coins, ARRAY_SIZE(coins), 13) << endl;
	cout << coinChanging(coins, ARRAY_SIZE(coins), 16) << endl;
	return 0;
}
