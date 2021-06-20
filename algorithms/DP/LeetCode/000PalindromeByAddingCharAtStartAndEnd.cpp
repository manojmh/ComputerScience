/**
1) "aaba" => "aabaa"
String "aaba" can be converted to palindrome by adding just "a" at the end
2) "abaa" => "aabaa"
String "abaa" can be converted to palindrome by adding just "a" at the begining
3) "cabad" => "dcabacd"
String "cabad" can be converted to palindrome by adding "c" to lps and "d" to begining of lps
**/
class Solution {
public:
  string longestPalindrome(string s) {
    int mx = INT_MIN;
    string res;
    vector<vector<bool>> t(s.length(), vector<bool>(s.length(), false));
    for(int g=0; g<=s.length(); g++) {
      for(int i=0, j=g; j<s.length(); i++,j++) {
        if(g==0) {
          t[i][j] = true;
        }
        else if(g==1) {
          if(s[i]==s[j])
            t[i][j] = true;
          else
            t[i][j] = false;
        }
        else {
          if(s[i]==s[j]) {
            if(t[i+1][j-1]==true)
              t[i][j] = true;
            else
              t[i][j] = false;
          }
          else {
            t[i][j] = false;
          }
        }
        if(t[i][j] == true) {
          if(mx < j-i+1) {
            mx = j-i+1;
            res = s.substr(i,j-i+1);
          }
        }
      }
    }
    return res;
  }
  string shortestPalindrome(string s) {
    string lps = longestPalindrome(s);
    if(s.length() == lps.length()) return lps;
    const char *p  = strstr(s.c_str(), lps.c_str());
    int pos = p-s.c_str();
    if(pos == 0) {
      string temp = s.substr(lps.length(), s.length()-lps.length());
      reverse(temp.begin(), temp.end());
      return temp+s;
    }
    else if(pos+lps.length() == s.length()) {
      string temp = s.substr(0, pos);
      reverse(temp.begin(), temp.end());
      return s+temp;
    }
    else {
      string res = "";
      string temp1 = s.substr(0, pos);
      res = temp1;
      res += lps;
      reverse(temp1.begin(), temp1.end());
      res += temp1;

      string temp2 = s.substr(pos+lps.length(), s.length()-pos+lps.length());
      res += temp2;
      reverse(temp2.begin(), temp2.end());
      res = temp2 + res;
      return res;
    }
    return "";
  }
};
