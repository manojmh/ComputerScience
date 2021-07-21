/**
https://leetcode.com/problems/range-module/
https://www.youtube.com/watch?v=LV_KASL1smE
A Range Module is a module that tracks ranges of numbers. Design a data structure to track the ranges represented as half-open intervals and query about them.
A half-open interval [left, right) denotes all the real numbers x where left <= x < right.
Implement the RangeModule class:
RangeModule() Initializes the object of the data structure.
void addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval.
Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
boolean queryRange(int left, int right) Returns true if every real number in the interval [left, right) is currently being tracked, and false otherwise.
void removeRange(int left, int right) Stops tracking every real number currently being tracked in the half-open interval [left, right).
Example 1:
Input
["RangeModule", "addRange", "removeRange", "queryRange", "queryRange", "queryRange"]
[[], [10, 20], [14, 16], [10, 14], [13, 15], [16, 17]]
Output
[null, null, null, true, false, true]
Explanation
RangeModule rangeModule = new RangeModule();
rangeModule.addRange(10, 20);
rangeModule.removeRange(14, 16);
rangeModule.queryRange(10, 14); // return True,(Every number in [10, 14) is being tracked)
rangeModule.queryRange(13, 15); // return False,(Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
rangeModule.queryRange(16, 17); // return True, (The number 16 in [16, 17) is still being tracked, despite the remove operation)
Constraints:
1 <= left < right <= 109
At most 104 calls will be made to addRange, queryRange, and removeRange.
**/
static const auto _____ = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class RangeModule {
private:
  map<int, int> m_intervals;
  bool get_overlapped_region(int left, int right, map<int, int>::iterator& it_left, map<int, int>::iterator& it_right){
    it_left = m_intervals.upper_bound(left);
    it_right = m_intervals.upper_bound(right);
    if (it_left != m_intervals.begin()) {
      it_left--;
      if (it_left->second < left) {
        it_left++;
      }
    }
    return it_left != it_right;
  }
public:
  RangeModule() {}
  void addRange(int left, int right) {
    map<int, int>::iterator it_left = m_intervals.end();
    map<int, int>::iterator it_right = m_intervals.end();
    if (get_overlapped_region(left, right, it_left, it_right)) {
      auto it_last = std::prev(it_right);
      left = min(left, it_left->first);
      right = max(right, it_last->second);
      m_intervals.erase(it_left, it_right);
    }
    m_intervals[left] = right;
  }
  bool queryRange(int left, int right) {
    map<int, int>::iterator it_left = m_intervals.end();
    map<int, int>::iterator it_right = m_intervals.end();
    if (!get_overlapped_region(left, right, it_left, it_right)) {
      return false;
    }
    return it_left->first <= left && it_left->second >= right;
  }
  void removeRange(int left, int right) {
    map<int, int>::iterator it_left = m_intervals.end();
    map<int, int>::iterator it_right = m_intervals.end();
    if (!get_overlapped_region(left, right, it_left, it_right)) {
      return;
    }
    auto it_last = std::prev(it_right);
    int start = min(left, it_left->first);
    int end = max(right, it_last->second);
    m_intervals.erase(it_left, it_right);
    if (start < left) m_intervals[start] = left;
    if (end > right) m_intervals[right] = end;
  }
};
