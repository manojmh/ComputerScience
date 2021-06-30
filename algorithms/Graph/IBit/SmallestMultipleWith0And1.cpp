/**
https://www.interviewbit.com/old/problems/smallest-multiple-with-0-and-1/
You are given an integer N. You have to find smallest multiple of N which consists of digits 0 and 1 only.
Since this multiple could be large, return it in form of a string.
Note:
Returned string should not contain leading zeroes.
For example,
For N = 55, 110 is smallest multiple consisting of digits 0 and 1.
For N = 2, 10 is the answer.
**/
string Solution::multiple(int A) {
  if(A == 1) return "1";
  string s = "1";
  vector<int>parent(A, -1);
  vector<int>bit(A, -1);
  queue<int>q;
  parent[1] = 1;
  q.push(1);
  bit[1] = 1;
  while(!q.empty()) {
    int f = q.front();
    q.pop();
    if(f==0)
      break;
    int left = ((f*10)+0) % A;
    int right = ((f*10)+1) % A;
    if(parent[left] == -1) {
      parent[left] = f;
      bit[left] = 0;
      q.push(left);
    }
    if(parent[right] == -1) {
      parent[right] = f;
      bit[right] = 1;
      q.push(right);
    }
  }
  string ans;
  int curr = 0;
  while(parent[curr] != curr) {
    ans += to_string(bit[curr]);
    curr = parent[curr];
  }
  ans += "1";
  return string(ans.rbegin(), ans.rend());
}
