/**
https://www.interviewbit.com/old/problems/smallest-sequence-with-given-primes/
GIven three prime numbers A, B and C and an integer D.
You need to find the first(smallest) D integers which only have A, B, C or a combination of them as their prime factors.
Input Format
First argument is an integer A.
Second argument is an integer B.
Third argument is an integer C.
Fourth argument is an integer D.
Output Format
Return an array of size D denoting the first smallest D integers which only have A, B, C or a combination of them as their prime factors.
NOTE: You need to return the array sorted in ascending order.
Example Input
Input 1:
A = 2
B = 3
C = 5
D = 5
Example Output
Output 1: [2, 3, 4, 5, 6]
Example Explanation
Explanation 1:
4 = A * A i.e ( 2 * 2 ) 
6 = A * B i.e ( 2 * 3 )
**/
vector<int> Solution::solve(int A, int B, int C, int D) {
  vector<int> out;
  out.push_back(1);
  int i=0, j=0, k=0;
  while(D--) {
    int mn = min(out[i]*A, min(out[j]*B, out[k]*C));
    out.push_back(mn);
    if(mn == out[i]*A) i++;
    if(mn == out[j]*B) j++;
    if(mn == out[k]*C) k++;
  }
  out.erase(out.begin());
  return out;
}
