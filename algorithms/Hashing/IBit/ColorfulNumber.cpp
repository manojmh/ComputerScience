/**
https://www.interviewbit.com/problems/colorful-number/
For Given Number N find if its COLORFUL number or not
Return 0/1
COLORFUL number:
A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:
N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 
Output : 1
**/
int Solution::colorful(int A) {
  vector<int> nums;
  while(A) {
    nums.push_back(A%10);
    A=A/10;
  }
  set<int> s;
  for(int i=0; i<nums.size(); i++) {
    if(s.find(nums[i]) != s.end())
      return 0;
    s.insert(nums[i]);
  }
  for(int i=0; i<nums.size(); i++) {
    int mul = nums[i];
    for(int j=i+1; j<nums.size(); j++) {
      mul *= nums[j];
      if(s.find(mul) != s.end())
        return 0;
      s.insert(mul);
    }
  }
  return 1;
}
