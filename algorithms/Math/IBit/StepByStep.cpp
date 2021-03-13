/** Toppr
Given a target A on an infinite number line, i.e. -infinity to +infinity.
You are currently at position 0 and you need to reach the target by moving according to the below rule:
In ith move you can take i steps forward or backward.
Find the minimum number of moves required to reach the target.
Problem Constraints
-109 <= A <= 109
Input Format
First and only argument is an integer A.
Output Format
Return an integer denoting the minimum moves to reach target.
Example Input
Input 1:3
Input 2:2
Example Output
Output 1: 2
Output 2: 3
Example Explanation
Explanation 1:
On the first move we step from 0 to 1.
On the second step we step from 1 to 3.
Explanation 2:
On the first move we step from 0 to 1.
On the second move we step  from 1 to -1.
On the third move we step from -1 to 2.

Explanation 3: Intution
cur : 1  a : 5 | cur%2 : 1 a%2 : 1
cur : 3  a : 5 | cur%2 : 1 a%2 : 1
cur : 6  a : 5 | cur%2 : 0 a%2 : 1
cur : 10 a : 5 | cur%2 : 0 a%2 : 1
------------------------------------
cur : 15 a : 5 | cur%2 : 1 a%2 : 1 | cur>=a && cur%2 == a%2
------------------------------------
**/
int Solution::solve(int a) {
  int i;
  a=abs(a);
  if(a==0)return 0;
  for(i=1;;i++){
    int cur=(i*(i+1))/2;
    //cout << "cur : " << cur << " a : " << a << " | " << " cur%2 : " << cur%2 << " a%2 : " << a%2 << "\n";
    if(cur>=a && cur%2==a%2)return i;
  }
  return i;
}
