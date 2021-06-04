/**
https://www.interviewbit.com/problems/palindrome-partitioning/
Given a string s, partition s such that every string of the partition is a palindrome.
Return all possible palindrome partitioning of s.
For example, given s = "aab",
Return
  [
    ["a","a","b"]
    ["aa","b"],
  ]
 Ordering the results in the answer : Entry i will come before Entry j if :
len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
(len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
In the given example,
["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")
**/
bool isPalin(string s, int low, int high) {
  while(low <= high) {
    if(s[low] != s[high])
      return false;
    low++;
    high--;
  }
  return true;
}
void part(vector<vector<string>> &out, vector<string> &tempOut, int i, int n, string A) {
  if(i == A.size()) {
    out.push_back(tempOut);
    return;
  }
  for(int j=i; j<n; j++) {
    string str(A.substr(i, j-i+1));
    if(isPalin(str, 0, str.length()-1)) {
      tempOut.push_back(str);
      part(out, tempOut, j+1, n, A);
      tempOut.pop_back();
    }
  }
}
vector<vector<string>> Solution::partition(string A) {
  vector<vector<string>> res;
  vector<string> s;
  part(res, s, 0, A.size(), A);
  return res;
}
