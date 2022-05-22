/*
Given a set of distinct numbers, find all of its permutations.
Permutation is defined as the re-arranging of the elements of the set. For example, {1, 2, 3} has the following six permutations:
{1, 2, 3}
{1, 3, 2}
{2, 1, 3}
{2, 3, 1}
{3, 1, 2}
{3, 2, 1}
If a set has ‘n’ distinct elements it will have n!n! permutations.
Example 1:
Input: [1,3,5]
Output: [1,3,5], [1,5,3], [3,1,5], [3,5,1], [5,1,3], [5,3,1]
*/
class Permutations {
public:
  static vector<vector<int>> findPermutations(const vector<int>& nums) {
    vector<vector<int>> res;
    queue<vector<int>> q;
    q.push(vector<int>());
    for(auto cur:nums) {
      int n = q.size();
      for(int j=0; j<n; j++) {
        //old permutation
        vector<int> op(q.front());
        q.pop();
        for(int i=0; i<=op.size(); i++) {
          //new permutation
          vector<int> np(op);
          np.insert(np.begin()+i, cur);
          if(np.size() == nums.size())
            res.push_back(np);
          else
            q.push(np);
        }
      }
    }
    return res;
    }
};
