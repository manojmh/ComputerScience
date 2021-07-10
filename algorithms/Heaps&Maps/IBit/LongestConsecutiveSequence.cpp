/**
https://www.interviewbit.com/old/problems/longest-consecutive-sequence/
https://www.youtube.com/watch?v=qgizvmgeyUM
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
Example:
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity.
**/
int Solution::longestConsecutive(const vector<int> &A) {
  if(A.size()<=1) return 1;
  set<int> s;
  for(int i=0; i<A.size(); i++)
    s.insert(A[i]);
  int mxCount = 0;
  for(int i=0; i<A.size(); i++) {
    if(s.find(A[i]-1) == s.end()) {
      int cur = A[i];
      int count = 1;
      while(s.find(cur+1)!=s.end()) {
        count++;
        cur++;
      }
      mxCount = max(mxCount, count);
    }
  }
  return mxCount;
}
