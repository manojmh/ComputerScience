#include <iostream>
#include <vector>
using namespace std;

//Utility function to get the sum
int getSum(vector<int> freq, int i, int j)
{
    int sum = 0;
    for(int x=i; x<=j; x++)
    {
        sum += freq[x];
    }
    return sum;
}

//Utility function to calculate the min cost of a BST
int minCost(vector<int> input, vector<int> freq)
{
    int len = input.size();
    int T[len][len];
    
    for(int i=0; i<len; i++)
        T[i][i] = freq[i];
    
    for(int l=2; l<=len; l++)
    {
        for(int i=0; i<=len-1; i++)
        {
            int j=i+l-1;
            T[i][j] = 100000;
            int sum = getSum(freq, i, j);
            
            for(int k=i; k<=j; k++)
            {
                int val = sum + (k-1<i?0:T[i][k-1]) + (k+1>j?0:T[k+1][j]);
                if(val < T[i][j])
                    T[i][j] = val;
            }
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
    vector<int> input {10,12,16,21};
    vector<int> freq {4,2,6,3};
    
    cout << "\n\nMinimum cost of BST is : " << minCost(input, freq) << endl;
    return 0;
}
