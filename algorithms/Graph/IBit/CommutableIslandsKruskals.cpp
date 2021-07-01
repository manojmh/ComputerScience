/**
https://www.interviewbit.com/old/problems/commutable-islands/
There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.
We need to find bridges with minimal cost such that all islands are connected.
It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.
Input Format:
The first argument contains an integer, A, representing the number of islands.
The second argument contains an 2-d integer matrix, B, of size M x 3:
=> Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].
Output Format:
Return an integer representing the minimal cost required.
Constraints:
1 <= A, M <= 6e4
1 <= B[i][0], B[i][1] <= A
1 <= B[i][2] <= 1e3
Examples:
Input 1:
A = 4
B = [   
      [1, 2, 1]
      [2, 3, 4]
      [1, 4, 3]
      [4, 3, 2]
      [1, 3, 10]
    ]
Output 1: 6
Explanation 1: We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.
Input 2:
A = 4
B = [
      [1, 2, 1]
      [2, 3, 2]
      [3, 4, 4]
      [1, 4, 3]
    ]
Output 2: 6
Explanation 2: We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred will be (1 + 2 + 3) = 6.
**/
#define N 100005
int n = 0;
vector<pair<int, pair<int,int>>> v;
int p[N];
int rank11[N];
void create_set() {
  for(int i=1; i<=n; i++) {
    p[i] = i;
    rank11[i] = 0;
  }
}
int find_set(int u) {
  int x = p[u];
  if(x != u)
    x = find_set(x);
  return x;
}
void merge_set(int u, int v) {
  int s1 = find_set(u);
  int s2 = find_set(v);
  if(rank11[s1] > rank11[s2])
    p[s2] = s1;
  else
    p[s1] = s2;
  if(rank11[s1] == rank11[s2])
    rank11[s2] += 1;
}
int kruskal() {
  create_set();
  int res = 0;
  for(int i=0; i<v.size(); i++) {
    int src = v[i].second.first;
    int dst = v[i].second.second;
    if(find_set(src) != find_set(dst)) {
      res += v[i].first;
      merge_set(src, dst);
    }
  }
  return res;
}
int Solution::solve(int A, vector<vector<int> > &B) {
  n = A;
  v.clear();
  for(int i=0; i<B.size(); i++) {
    v.push_back({B[i][2], {B[i][0], B[i][1]}});
  }
  sort(v.begin(), v.end());
  return kruskal();
}
