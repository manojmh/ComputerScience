/*
Given a string, find all of its permutations preserving the character sequence but changing case.

Example 1:
Input: "ad52"
Output: "ad52", "Ad52", "aD52", "AD52" 

Example 2:
Input: "ab7c"
Output: "ab7c", "Ab7c", "aB7c", "AB7c", "ab7C", "Ab7C", "aB7C", "AB7C"
*/
vector<string> permute(string str) {
  if(str=="")
    return vector<string>();

  vector<string> res;
  res.push_back(str);
  for(int i=0; i<str.size(); i++) {
    if(!isalpha(str[i])) continue;

    int n = res.size();
    for(int j=0; j<n; j++) {
      string temp(res[j]);
      if(isupper(temp[i]))
        temp[i] = tolower(temp[i]);
      else
        temp[i] = toupper(temp[i]);
      res.push_back(temp);
    }
  }
  return res;
}
