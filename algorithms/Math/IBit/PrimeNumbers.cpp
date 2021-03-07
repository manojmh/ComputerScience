/**
Given a number N, find all prime numbers upto N ( N included ).
Example: if N = 7, all primes till 7 = {2, 3, 5, 7}
Make sure the returned array is sorted.
**/
vector<int> Solution::sieve(int A) {
  vector<int> res;
  if(A<2) return res;

  vector<int> primes(A+1, 1);
  primes[0] = 0;
  primes[1] = 0;
  for(int i=2; i*i<=A; i++) {
    if(primes[i] == 1) {
      for(int j=i*i; j<=A; j+=i) {
          primes[j] = 0;
      }
    }
  }
  for(int i=2; i<=A; i++)
    if(primes[i] == 1)
      res.push_back(i);
  return res;
}
