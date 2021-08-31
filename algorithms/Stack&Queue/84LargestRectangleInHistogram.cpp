/**
https://leetcode.com/problems/largest-rectangle-in-histogram/
84. Largest Rectangle in Histogram
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
return the area of the largest rectangle in the histogram.
Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:
Input: heights = [2,4]
Output: 4
Constraints:
1 <= heights.length <= 105
0 <= heights[i] <= 104
**/
class Solution {
  vector<int> NSLI(vector<int> &arr) {
    vector<int> v;
    stack<int> s;
    for(int i=0; i<arr.size(); i++) {
      if(s.empty())
        v.push_back(-1);
      else if(arr[s.top()] < arr[i])
        v.push_back(s.top());
      else if(arr[s.top()] >= arr[i]) {
        while(!s.empty() && arr[s.top()] >= arr[i])
          s.pop();
        if(s.empty())
          v.push_back(-1);
        else
          v.push_back(s.top());
      }
      s.push(i);
    }
    //for(auto a:v) cout << a << " ";
    //cout << endl;
    return v;
  }
  vector<int> NSRI(vector<int> &arr) {
    vector<int> v; stack<int> s;
    for(int i=arr.size()-1; i>=0; i--) {
      if(s.empty())
        v.push_back(-1);
      else if(arr[s.top()] < arr[i])
        v.push_back(s.top());
      else if(arr[s.top()] >= arr[i]) {
        while(!s.empty() && arr[s.top()] >= arr[i])
          s.pop();
        if(s.empty())
          v.push_back(-1);
        else
          v.push_back(s.top());
      }
      s.push(i);
    }
    reverse(v.begin(), v.end());
    //for(auto a:v) cout << a << " ";
    //cout << endl;
    return v;
  }
public:
  int largestRectangleArea(vector<int>& arr) {
    arr.insert(arr.begin(),0);
    arr.push_back(0);
    vector<int> nsl = NSLI(arr);
    vector<int> nsr = NSRI(arr);
    int maxArea = INT_MIN;
    for(int i=0; i<arr.size(); i++) {
      int area = arr[i] * (nsr[i]-nsl[i]-1);
      maxArea = max(maxArea, area);
    }
    //cout << "\n====================\n";
    return maxArea;
  }
};
