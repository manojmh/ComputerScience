/**
https://leetcode.com/problems/sliding-window-maximum/
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.
Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:
Input: nums = [1], k = 1
Output: [1]
Example 3:
Input: nums = [1,-1], k = 1
Output: [1,-1]
Example 4:
Input: nums = [9,11], k = 2
Output: [11]
Example 5:
Input: nums = [4,-2], k = 2
Output: [4]
Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
**/
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> res;
    // Create a Double Ended Queue, Qi that will store indexes
    // of array elements. The queue will store indexes of useful elements in every
    // window and it will maintain decreasing order of values from front to rear in Qi, i.e.,
    // arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order
    std::deque<int> Qi(k);

    //Process first k (or first window) elements of array
    int i;
    for (i = 0; i < k; ++i) {
      // For every element, the previous
      // smaller elements are useless so
      // remove them from Qi
      while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
        // Remove from rear
        Qi.pop_back();

      // Add new element at rear of queue
      Qi.push_back(i);
    }

    // Process rest of the elements,
    // i.e., from arr[k] to arr[n-1]
    for (; i < n; ++i) {
      // The element at the front of
      // the queue is the largest element of
      // previous window, so print it
      res.push_back(arr[Qi.front()]);

      // Remove the elements which
      // are out of this window
      while ((!Qi.empty()) && Qi.front() <= i - k)
        // Remove from front of queue
        Qi.pop_front();

      // Remove all elements
      // smaller than the currently
      // being added element (remove
      // useless elements)
      while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
        Qi.pop_back();

      // Add current element at the rear of Qi
      Qi.push_back(i);
    }
    // Print the maximum element
    // of last window
    res.push_back(arr[Qi.front()]);
    return res;
  }
};
