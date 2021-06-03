/**
https://www.interviewbit.com/problems/longest-substring-without-repeat/
Given a string,
find the length of the longest substring without repeating characters.
Example:
The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.
**/
int Solution::lengthOfLongestSubstring(string A) {
  int n=A.size();
  if(n<=1)
    return n;

  unordered_map<char,int> mp;
  int start=0,end=0;
  int mx=INT_MIN;
  while(end<n){
    mp[A[end]]++;
    while(mp[A[end]]>1){
      mp[A[start]]--;
      start++;
    }
    mx=max(end-start+1,mx);
    end++;
  }
  return mx;
}
