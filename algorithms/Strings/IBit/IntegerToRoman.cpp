/**
https://www.interviewbit.com/problems/integer-to-roman/
Another question which belongs to the category of questions which are intentionally stated vaguely.
Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.
Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman numeral version
Note : This question has a lot of scope of clarification from the interviewer.
Please take a moment to think of all the needed clarifications and
see the expected response using “See Expected Output” 
For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations. 
Input Format
The only argument given is integer A.
Output Format
Return a string denoting roman numeral version of A.
Constraints : 1 <= A <= 3999
For Example Input 1: A = 5 Output 1: "V"
Input 2:A = 14 Output 2: "XIV"
**/
string Solution::intToRoman(int str) {
  string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
  string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
  string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
  string res;
  string A = to_string(str);
  int n = A.size()-1;
  int i = 0;
  while(i<=n) {
    if(n-i+1 == 4) {
      for(int j=1; j<=A[i]-'0'; j++)
        res+='M';
    }
    else if(n-i+1 == 3)
      res += hundreds[A[i]-'0'];
    else if(n-i+1 == 2)
      res += tens[A[i]-'0'];
    else
      res += ones[A[i]-'0'];
    i++;
  }
  return res;
}
//Editorial 1:
string intToRoman(int num) {
  // 1000, 2000, 3000
  string M[] = {"", "M", "MM", "MMM"};
  // 100, 200, 300, .. 900
  string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
  // 10, 20, ... 90
  string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
  // 1, 2, ... 9
  string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
  return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}
//Editorial 2:
string Solution::intToRoman(int A) {
  string ans = "";
  while(A) {
    if(A-1000>=0) {
      ans+="M";
      A-=1000;
    }
    else if(A-900>=0) {
      ans+="CM";
      A-=900;
    }
    else if(A-500>=0) {
      ans+="D";
      A-=500;
    }
    else if(A-400>=0) {
      ans+="CD";
      A-=400;
    }
    else if(A-100>=0) {
      ans+="C";
      A-=100;
    }
    else if(A-90>=0) {
      ans+="XC";
      A-=90;
    }
    else if(A-50>=0) {
      ans+="L";
      A-=50;
    }
    else if(A-40>=0) {
      ans+="XL";
      A-=40;
    }
    else if(A-10>=0) {
      ans+="X";
      A-=10;
    }
    else if(A-9>=0) {
      ans+="IX";
      A-=9;
    }
    else if(A-5>=0) {
      ans+="V";
      A-=5;
    }
    else if(A-4>=0) {
      ans+="IV";
      A-=4;
    }
    else {
      ans+="I";
      A-=1;
    }
  }
  return ans;
}
