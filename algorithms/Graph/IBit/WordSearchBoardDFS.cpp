/**
https://www.interviewbit.com/old/problems/word-search-board/
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell,
where "adjacent" cells are those horizontally or vertically neighboring.
The cell itself does not count as an adjacent cell.
The same letter cell may be used more than once.
Example :
Given board =
[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns 1,
word = "SEE", -> returns 1,
word = "ABCB", -> returns 1,
word = "ABFSAB" -> returns 1
word = "ABCD" -> returns 0
Note that 1 corresponds to true, and 0 corresponds to false.
**/
bool dfs(vector<string>A,int i,int j,string word,int idx){
  if(i<0 || i>=A.size() || j<0 || j>=A[0].length() || word[idx]!=A[i][j])
  return false;
  if(idx==word.length()-1)
  return true;
  bool res=dfs(A,i+1,j,word,idx+1) ||
  dfs(A,i-1,j,word,idx+1) ||
  dfs(A,i,j+1,word,idx+1) ||
  dfs(A,i,j-1,word,idx+1);
  return res;
}

int Solution::exist(vector<string> &A, string B) {
  for(int i=0;i<A.size();i++){
    for(int j=0;j<A[0].length();j++){
      if(A[i][j]==B[0] && dfs(A,i,j,B,0))
      return 1;
    }
  }
  return 0;
}
