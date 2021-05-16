/**
https://leetcode.com/problems/maximal-rectangle/
https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
Example 1: Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]] Output: 6
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Explanation: The maximal rectangle is shown in the above picture.
Example 2: Input: matrix = [] Output: 0
Example 3: Input: matrix = [["0"]] Output: 0
Example 4: Input: matrix = [["1"]] Output: 1
Example 5: Input: matrix = [["0","0"]] Output: 0
Constraints:
rows == matrix.length
cols == matrix[i].length
0 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
**/
class Solution {
public:
  vector<int> NSLI(vector<int> &a) {
    stack<int> s;
    vector<int> v;
    for(int i=0; i<a.size(); i++) {
      if(s.empty()) v.push_back(-1);
      else if(a[s.top()] < a[i]) v.push_back(s.top());
      else if(a[s.top()] >= a[i]) {
        while(!s.empty() && a[s.top()] >= a[i])
          s.pop();
        if(s.empty())
          v.push_back(-1);
        else
          v.push_back(s.top());
      }
      s.push(i);
    }
    return v;
  }
  vector<int> NSRI(vector<int> &a) {
    stack<int> s;
    vector<int> v;
    for(int i=a.size()-1; i>=0 ; i--) {
      if(s.empty()) v.push_back(a.size());
      else if(a[s.top()] < a[i]) v.push_back(s.top());
      else if(a[s.top()] >= a[i]) {
        while(!s.empty() && a[s.top()] >= a[i])
          s.pop();
        if(s.empty())
          v.push_back(a.size());
        else
          v.push_back(s.top());
      }
      s.push(i);
    }
    reverse(v.begin(), v.end());
    return v;
  }
  int maximalRectangle(vector<vector<char>>& a) {
    if(a.size() < 1) return 0;
    vector<int> temp(a[0].size(), 0);
    int maxArea = INT_MIN;
    for(int i=0; i<a.size(); i++) {
      for(int j=0; j<a[i].size(); j++) {
        if((a[i][j] - '0') == 0)
          temp[j] = 0;
        else
          temp[j] += (a[i][j] - '0');
      }
      vector<int> nsl = NSLI(temp);
      vector<int> nsr = NSRI(temp);
      int maxAreaRow = INT_MIN;
      for(int k=0; k<temp.size(); k++) {
        int area = temp[k] * (nsr[k] - nsl[k] - 1);
        maxAreaRow = max(maxAreaRow, area);
      }
      maxArea = max(maxArea, maxAreaRow);
    }
    return maxArea;
  }
};

//Editorial using Kadane's Algorithm:
void kadane(vector<int> temp, int &start, int &finish, int size, int value) {
  int max=0;
  for(int i=0;i<size;) {
    int j=i, f=0;
    while(j<size && temp[j]==value) {
      j++;
      f=1;
    }
    if(f==0) {
      i++;
      continue;
    }
    if(j-i>max) {
      max=j-i;
      start=i;
      finish=j-1;
    }
    i=j;
  }
}
int Solution::maximalRectangle(vector<vector<int> > &A)  {
  if(A.size()==0 || A[0].size()==0)
    return 0;
  int right, left, n=A.size(), m=A[0].size(), max=0, start, finish, f=0;
  for(left=0;left<m;left++) {
    vector<int> temp(n,0);
    int area=-1;
    for(right=left;right<m;right++) {
      start=-1; finish=-1;
      for(int i=0;i<n;i++)
        temp[i]+=A[i][right];
      kadane(temp,start,finish,n,right-left+1);
      if(start!=-1)
        area=(right-left+1)*(finish-start+1);
      if(area>max)
        max=area;
    }
  }
  return max;
}
