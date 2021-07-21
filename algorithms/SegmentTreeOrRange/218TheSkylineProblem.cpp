/**
https://leetcode.com/problems/the-skyline-problem/
https://www.youtube.com/watch?v=GSBLe8cKu0s&t=876s
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance.
Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.
The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:
lefti is the x coordinate of the left edge of the ith building.
righti is the x coordinate of the right edge of the ith building.
heighti is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...].
Each key point is the left endpoint of some horizontal segment in the skyline except
the last point in the list, which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends.
Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.
Note: There must be no consecutive horizontal lines of equal height in the output skyline.
For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable;
the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]
Example 1:
Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.
Example 2:
Input: buildings = [[0,2,3],[2,5,3]]
Output: [[0,3],[5,0]]
Constraints:
1 <= buildings.length <= 104
0 <= lefti < righti <= 231 - 1
1 <= heighti <= 231 - 1
buildings is sorted by lefti in non-decreasing order.
**/
enum method_t{
    START = 0,
    END
};
struct entry{
  int point;
  int height;
  method_t method;
  entry(int p, int h, method_t m) {
    point = p;
    height = h;
    method = m;
  }
};
static int comp(const entry &a, const entry &b) {
  if(a.point == b.point) {
    if(a.method == START && b.method==START)
      return a.height>b.height; //Return point with greater height
    if(a.method == END && b.method==END)
      return a.height<b.height; //Return point with lesser height
    //if(a.method == START && b.method==END)
      return true;
    //if(a.method == END && b.method == START)
        //return false;

  }
  return a.point<b.point;
}
class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>> res;
    vector<entry> entries;
    for(int i=0; i<buildings.size(); i++) {
      entries.push_back(entry(buildings[i][0],  buildings[i][2], START));
      entries.push_back(entry(buildings[i][1],  buildings[i][2], END));
    }
    sort(entries.begin(), entries.end(), comp);
    map<int, int, greater<int>> m;
    int prevMax = 0;
    for(auto i=0; i<entries.size(); i++) {
      if(entries[i].method == START) {
        m[entries[i].height]++;
      }
      else {
        if(m.find(entries[i].height) != m.end()) {
          m[entries[i].height]--;
          if(m[entries[i].height] == 0)
            m.erase(entries[i].height);
        }
      }
        int curMax = m.begin()->first;
        if(curMax != prevMax) {
          vector<int> temp(2,0);
          temp[0] = entries[i].point;
          temp[1] =  curMax;
          res.push_back(temp);
          prevMax = curMax;
        }
    }
    return res;
  }
};
