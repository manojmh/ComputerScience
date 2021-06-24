/**
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
Return an integer corresponding to the maximum product possible.
Example :
Input : [2, 3, -2, 4]
Return : 6 
Possible with [2, 3]
Tricky TC:
i/p: -10 10 -10 10
o/p: 10000
**/
int Solution::maxProduct(const vector<int> &nums) {
  int length = nums.size();
  int result = nums[0];;
  int curr_max = nums[0];
  int curr_min = nums[0];

  for(int i =1; i < length; i++){
    int curr_max_prev= curr_max;
    curr_max = max(nums[i], max(curr_max*nums[i], curr_min*nums[i]));
    curr_min = min(nums[i], min(curr_max_prev*nums[i], curr_min*nums[i]));
    result = max(result,curr_max);
  }
  return result;
}
