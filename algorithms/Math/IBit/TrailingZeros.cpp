/** Microsoft Jabong Zillow
Given an integer A, return the number of trailing zeroes in A!.
Note: Your solution should be in logarithmic time complexity.
**Problem Constraints**
1 <= A <= 10000
**Input Format**
First and only argumment is integer A.
**Output Format**
Return an integer, the answer to the problem.
**Example Input**
Input 1:A = 4
Input 2:A = 5
**Example Output**
Output 1: 0
Output 2: 1
**Example Explanation**
Explanation 1:4! = 24
Explanation 2:5! = 120

Intituion : https://brilliant.org/wiki/trailing-number-of-zeros/
Find the number of trailing zeros in 500!500!.
The number of multiples of 5 that are less than or equal to 500 is 500 \div 5 =100.500÷5=100.
Then, the number of multiples of 25 is 500 \div 25 = 20.500÷25=20.
Then, the number of multiples of 125 is 500 \div 125 = 4.500÷125=4.
The next power of 5 is 625, which is greater than 500.
Therefore, the number of trailing zeros of 500!500! is 100+20+4=\boxed{124}.100+20+4= 124
**/
//Solution1:
int Solution::trailingZeroes(int A) {
  int i = 0;
  int j = 1;
  int count = 0;
  while((i = pow(5, j)) <= A){
    count += A/i;
    j++;
  }
  return count;
}
//Solution2:
class Solution {
public:
  int trailingZeroes(int n) {
    int sum = 0;
    while (n / 5 > 0) {
      sum += (n / 5);
      n /= 5;
    }
    return sum;
  }
};
