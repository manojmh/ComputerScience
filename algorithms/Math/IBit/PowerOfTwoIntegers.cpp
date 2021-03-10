/**
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0.
A and P both should be integers.
Example
Input : 4
Output : True  
as 2^2 = 4. 
**/
int Solution::isPower(int A) {
  int temp=A;
  if(A==1||A==0) return 1;
  for(int j=2;j*j<=A;j++) {
    while(A%j==0) {
      if(A/j==1)
        return 1;
      else 
        A=A/j;
    }
    A=temp;
  }
  return 0;
}
