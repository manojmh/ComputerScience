/**
Given a string A.
Return the string A after reversing the string word by word.
NOTE:
A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.
Input Format
The only argument given is string A.
Output Format
Return the string A after reversing the string word by word.
For Example
Input 1:
    A = "the sky is blue"
Output 1:
    "blue is sky the"
Input 2:
    A = "this is ib"
Output 2:
    "ib is this"
**/
string Solution::solve(string A) {
  if(A.size() == 0) return "";
  int i = 0;
  string temp;
  vector<string> vstr;
  while(i<A.size()) {
    if(i>0 && A[i] == ' ' && A[i-1] == ' ') {
        i++;
      continue;
    }
    else if(i>0 && A[i] == ' ') {
      vstr.push_back(temp);
      temp.clear();
    }
    else if(A[i] != ' ')
      temp.push_back(A[i]);
    i++;
  }
  string t1;
  for(int j=0; j<temp.size(); j++)
    if(temp[j] != ' ')
      t1.push_back(temp[j]);
  if(!t1.empty())
    vstr.push_back(t1);
  string s;
  if(vstr.size()>1) {
    for(int i=vstr.size()-1; i>0; i--)
      s += vstr[i] + " ";
    s += vstr[0];
  }
  else
    s = vstr[0];
  return s;
}
//Alternate solution:
string Solution::solve(string A) 
{
  string ans="", w;
  stringstream ss(A);
  while(ss>>w)
    ans=" "+w+ans;
  return(ans.substr(1));
}
