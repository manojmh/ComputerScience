/**
https://www.interviewbit.com/problems/simplify-directory-path/
Given a string A representing an absolute path for a file (Unix-style).
Return the string A after simplifying the absolute path.
Note: Absolute path always begin with ’/’ ( root directory ).
Path will not have whitespace characters.
Input Format: The only argument given is string A.
Output Format: Return a string denoting the simplified absolue path for a file (Unix-style).
For Example
Input 1: A = "/home/"
Output 1: "/home"
Input 2: A = "/a/./b/../../c/"
Output 2:"/c"
**/
string Solution::simplifyPath(string A) {
  stringstream ss(A);
  string token;
  vector<string> tokens;
  while(getline(ss, token, '/')) {
    if(token == ".") continue;
    if(token.size() == 0) continue;
    tokens.push_back(token);
  }
  stack<string> s;
  for(int i=0; i<tokens.size(); i++) {
    if(tokens[i] == "..") {
      if(!s.empty())
        s.pop();
    }
    else
      s.push(tokens[i]);
  }
  vector<string> res;
  while(!s.empty()) {
    res.push_back(s.top());
    s.pop();
  }
  reverse(res.begin(), res.end());
  string fin="/";
  for(auto m:res) {
    fin += m + "/";
  }
  if(fin.size() > 1 && fin[fin.length()-1] == '/') {
    fin = fin.substr(0, fin.size()-1);
  }
  return  fin;
}
