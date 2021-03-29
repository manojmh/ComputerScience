/** Facebook Google
Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.
Example :
Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 3 5]
Output : [3 3 5]
Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 5]
Output : [3 5]
NOTE : For the purpose of this problem ( as also conveyed by the sample case ),
assume that elements that appear more than once in both arrays should be included multiple times in the final output. 
**/
vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
  vector<int> res;
  map<int, int> m;
  for(auto a:A)
    m[a]++;
  for(auto b:B) {
    if(m.find(b) != m.end()) {
      if(m[b]) {
        res.push_back(b);
        m[b]--;
      }
    }
  }
  return res;
}
//Editorial, Space efficient solution
vector<int> intersect(vector<int> &A, vector<int> &B) {
  vector<int> intersection;
  int n1 = A.size();
  int n2 = B.size();
  int i = 0, j = 0;
  while (i < n1 && j < n2) {
    if (A[i] > B[j]) {
      j++;
    } else if (B[j] > A[i]) {
      i++;
    } else {
      intersection.push_back(A[i]);
      i++;
      j++;
    }
  }
  return intersection;
}
