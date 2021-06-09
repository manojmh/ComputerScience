/**
https://www.interviewbit.com/problems/compare-version-numbers/
Compare two version numbers version1 and version2.
If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 1.13 < 1.13.4
**/
unsigned long long int stoll1(string A) {
  unsigned long long int num1 = 0;
  int i =0;
  while(i<A.size())
    num1 = num1*10+(A[i++]-'0');
  return num1;
}
vector<unsigned long long> tokenize(string version1) {
  string s = "";
  vector<unsigned long long> v1;
  for(int i=0; i<version1.size(); i++) {
    if(version1[i]=='.') {
      v1.push_back(stoll1(s));
      s="";
    }
    else
      s+=version1[i];
  }
  v1.push_back(stoll1(s));
  return v1;
}
int Solution::compareVersion(string A, string B) {
  vector<unsigned long long> v1 = tokenize(A);
  vector<unsigned long long> v2 = tokenize(B);
  while(v1.size()>1 && v1.back() == 0) v1.pop_back();
  while(v2.size()>1 && v2.back() == 0) v2.pop_back();
  int i=0;
  while(i<v1.size() && i<v2.size()) {
    if((v1[i]) < (v2[i]))
     return -1;
    if((v1[i]) > (v2[i]))
     return 1;
    i++;
  }
  if(v1.size() < v2.size())
     return -1;
  if(v1.size() > v2.size())
     return 1;
  return 0;
}
