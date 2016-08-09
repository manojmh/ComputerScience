/*
* Date : 10/08/2016
* Author : Manoj Hanamshet
* Maximum subarray problem
* The maximum subarray problem is the task of finding the contiguous subarray within a one-dimensional array of numbers
* which has the largest sum. For example, for the sequence of values −2, 1, −3, 4, −1, 2, 1, −5, 4; the contiguous subarray
* with the largest sum is 4, −1, 2, 1, with sum 6.
* Ref : 
* https://en.wikipedia.org/wiki/Maximum_subarray_problem
* https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/SubRectangularMatrixWithMaximumSum.java
*/

#include <iostream>
using namespace std;

int Kadane(int a[], int n, int &start, int &end)
{
    int sum = 0, maxSum=0;
    int currStart = 0;

    for(int i=0; i<n; i++)
    {
        sum += a[i];

        if(sum < 0)
        {
            sum = 0;
            currStart = i+1;
        }

        if(maxSum < sum)
        {
            maxSum = sum;
            start = currStart;
            end = i;
        }
    }
    return maxSum;
}

int main()
{
    //Largest Sum Contiguous Subarray
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int start = -1, end = -1;
    int max_sum = Kadane(a, n, start, end);
    cout << "Maximum contiguous sum is : " << max_sum << endl;
    cout << "from : "  << start << endl;
    cout << "to : " << end << endl;
    return 0;
}
