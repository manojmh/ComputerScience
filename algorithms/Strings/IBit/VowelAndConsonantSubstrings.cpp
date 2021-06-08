/**
https://www.interviewbit.com/problems/vowel-and-consonant-substrings/
Given a string A consisting of lowercase characters.
You have to find the number of substrings in A which starts with vowel and end with consonants or vice-versa.
Return the count of substring modulo 109 + 7.
Problem Constraints
1 <= |A| <= 105
A consists only of lower-case characters.
Input Format
First argument is an string A.
Output Format
Return a integer denoting the the number of substrings in A which starts with vowel and end with consonants or vice-versa with modulo 109 + 7.
Example Input
Input 1: A = "aba"
Input 2: A = "a"
Example Output
Output 1:2
Output 2: 0
Example Explanation
Explanation 1: Substrings of S are : [a, ab, aba, b, ba, a]Out of these only 'ab' and 'ba' satisfy the condition for special Substring. So the answer is 2.
Explanation 2: No possible substring that start with vowel and end with consonant or vice-versa.
**/
const int mod = 1e9 + 7;

int Solution::solve(string s) {
  unordered_set<char> se{'a', 'e', 'i', 'o', 'u'};
  int n = s.length();
  vector<int> numVowels(n);
  if(se.find(s[0]) != se.end()) numVowels[0] = 1;
  // numVowels[i] = v means there are v vowels from
  // index 0 to i
  for (int i = 1; i < n; i++) {
    numVowels[i] = numVowels[i - 1];
    // char s[i] is a vowel
    if(se.find(s[i]) != se.end()) {
      numVowels[i]++;
    }
  }
  int res = 0;
  for(int i = 0; i < n; i++) {
    int v = numVowels[i];
    // if there are v vowels from 0 to i,
    // and there are total i + 1 characters
    // from 0 to i, then the rest of the chars
    // are obviously going to be consonants
    int k = i + 1 - v;

    // current char is a vowel
    // then add the number of consonants to res
    if(se.find(s[i]) != se.end()) {
      res = (res + k) % mod;
    }
    else {
      res = (res + v) % mod;
    }
  }
  return res;
}
//Editorial:
int Solution::solve(string A) {
  long long v=0;
  long long c=0;
  long long ans=0;
  long long mode=1000000007;
  for(int i=0;i<A.size();i++) {
    if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u') {
      v++;
      ans= (ans+c)%mode;
    }
    else {
      c++;
      ans=(ans+v)%mode;
    }
  }
  return (int)ans;
}
