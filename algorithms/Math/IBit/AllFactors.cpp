/**
Given a number N, find all factors of N.
Example:
N = 6 
factors = {1, 2, 3, 6}
Make sure the returned array is sorted.
**/
vector<int> Solution::allFactors(int A) {
  set<int> s;
  for(int i=1; i*i<=A; i++) {
    if(A%i == 0) {
      if(s.find(i) == s.end()) {
        s.insert(i);
        s.insert(A/i);
      }
    }
  }
  vector<int> res;
  for(auto a : s)
      res.push_back(a);
  return res;
}
