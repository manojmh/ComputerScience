/**
https://www.interviewbit.com/old/problems/cycle-in-undirected-graph/
Given an undirected graph having A nodes labelled from 1 to A with M edges given in a form of matrix B of size M x 2
where (B[i][0], B[i][1]) represents two nodes B[i][0] and B[i][1] connected by an edge.
Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.
NOTE:
The cycle must contain atleast three nodes.
There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.
Problem Constraints
1 <= A, M <= 3105
1 <= B[i][0], B[i][1] <= A
Input Format
The first argument given is an integer A representing the number of nodes in the graph.
The second argument given is an matrix B of size M x 2 which represents the M edges such that there is a edge between node B[i][0] and node B[i][1].
Output Format
Return 1 if cycle is present else return 0.
Example Input
Input 1:
A = 5
B = [  [1. 2]
       [1, 3]
       [2, 3]
       [1, 4]
       [4, 5]
    ]
Input 2:
A = 3
B = [  [1. 2]
       [1, 3]
    ]
Example Output
Output 1: 1
Output 2: 0
Example Explanation*
Explanation 1: There is a cycle in the graph i.e 1 -> 2 -> 3 -> 1 so we will return 1
Explanation 2: No cycle present in the graph so we will return 0.
**/
#define N 3*100005
int n = 0;
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
int Solution::solve(int A, vector<vector<int> > &B) {
  n=A;
  create_set();
  int res = 0;
  for(int i=0; i<B.size(); i++) {
    int src = B[i][0];
    int dst = B[i][1];
    if(find_set(src) == find_set(dst))
      return true;
    merge_set(src, dst);
  }
  return false;
}
