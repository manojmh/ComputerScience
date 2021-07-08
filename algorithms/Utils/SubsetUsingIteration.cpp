vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
  vector<vector<int>> res;
  for(int g=0; g<A.size(); g++) {
    for(int i=0; i<A.size()-g; i++) {
      vector<int> temp;
      for(int j=i; j<=i+g; j++) {
        temp.push_back(A[j]);
      }
      res.push_back(temp);
    }
  }
  return res;
}
