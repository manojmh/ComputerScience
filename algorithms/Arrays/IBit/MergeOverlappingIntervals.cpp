/**
https://www.interviewbit.com/problems/merge-overlapping-intervals/
Given a collection of intervals, merge all overlapping intervals.
For example:
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
Make sure the returned intervals are sorted.
**/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval i1, Interval i2) {
  return (i1.start < i2.start);
}
vector<Interval> Solution::merge(vector<Interval> &A) {
  vector<Interval> res;  
  sort(A.begin(), A.end(), compare);
  for(int i=0; i<A.size(); i++) {
    if(res.empty() || res.back().end < A[i].start)
      res.push_back(A[i]);
    else
      res.back().end = max(res.back().end, A[i].end);
  }
  return res;
}
