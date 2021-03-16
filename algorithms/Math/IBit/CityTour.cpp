/** https://www.interviewbit.com/problems/city-tour/?ref=similar_problems
There are A cities numbered from 1 to A. You have already visited M cities, the indices of which are given in an array B of M integers.
If a city with index i is visited, you can visit either the city with index i-1 (i >= 2) or the city with index i+1 (i < A) if they are not already visited.
Eg: if N = 5 and array M consists of [3, 4], then in the first level of moves, you can either visit 2 or 5.
You keep visiting cities in this fashion until all the cities are not visited.
Find the number of ways in which you can visit all the cities modulo 10^9+7.
Input Format
The 1st argument given is an integer A, i.e total number of cities.
The 2nd argument given is an integer array B, where B[i] denotes ith city you already visited.
Output Format
Return an Integer X % (1e9 + 7), number of ways in which you can visit all the cities.
Constraints
1 <= A <= 1000
1 <= M <= A
1 <= B[i] <= A
For Example
Input:
    A = 5
    B = [2, 5]
Output:
    6
Explanation:
    All possible ways to visit remaining cities are :
    1. 1 -> 3 -> 4
    2. 1 -> 4 -> 3
    3. 3 -> 1 -> 4
    4. 3 -> 4 -> 1
    5. 4 -> 1 -> 3
    6. 4 -> 3 -> 1
https://www.youtube.com/watch?v=fUS9G-WG9SQ
//Formula:
//         n!
//t = -------------
//    n1!*n2!...ni!

//            (n1-1)   (n2-1) ....  (ni-1)
//ans =  t * 2^     * 2^         * 2^
**/
#define mod 1000000007
long long power(long long a, long long n) {
  if(n == 0) return 1;
  if(n == 1) return a;

  long long temp = power(a, n/2)%mod;

  if(n%2 == 0) return (temp * temp) % mod;

  return ((((a * temp) % mod) * temp) % mod) % mod;
}

long long fact(long long n) {
  long long ans = 1;
  for(long long i = 2; i<=n; i++) {
    ans = ans * i;
    ans = ans % mod;
  }
  return ans;
}
// Example input 1 2 3 (4) 5 6 7 8 (9) 10 11
int Solution::solve(int A, vector<int> &B) {
  sort(B.begin(), B.end());
  int n = A - B.size();

  //Identify the terms firstTerm n1 n2 n3 lastTerm
  vector<int> terms;
  //firstTerm
  //ex: push 1
  terms.push_back(B[0]-1);
  //middleTerms
  //ex: push 4-1 = 3
  //ex: push 9-4-1 = 4
  for(int i=1; i<B.size(); i++)
    terms.push_back(B[i]-B[i-1]-1);
  //lastTerm
  //ex: push 11-9 = 2
  terms.push_back(A-B.back());
  //ex: terms contains 1 3 4 2

  //Formula:
  //         n!
  //t = -------------
  //    n1!*n2!...ni!

  //            (n1-1)   (n2-1) ....  (ni-1)
  //ans =  t * 2^     * 2^         * 2^

  //fatorial of all possibilities
  long long ans = fact(n)%mod;

  //removing the terms with fixed relative orders
  // a/b can also be written as (a*(b^-1))
  // (a*(b^-1)) can also be written as (a*(b^(mod-2)))
  for(int i=0; i<terms.size(); i++) {
    ans = ans * (power(fact(terms[i]), mod-2)%mod);
    ans = ans % mod;
  }

  //adding back the middle terms by multiplying (2^(ni-1)) 
  long long int z = 1;
  for(int i=0; i<terms.size(); i++) {
    if((i==0) || (i==terms.size()-1))
      z *= 1;
    else {
      if(terms[i]<2) continue;
        z = z * power(2, terms[i]-1);
        z = z % mod;
    }
  }
  ans = (ans*z)%mod;
  return ans%mod;
}
