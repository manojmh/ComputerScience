/**
https://www.interviewbit.com/old/problems/word-ladder-i/
Given two words A and B, and a dictionary, C, find the length of shortest transformation sequence from A to B, such that:
You must change exactly one character in every transformation.
Each intermediate word must exist in the dictionary.
Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
Input Format:
The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains an array of strings, C.
Output Format:
Return an integer representing the minimum number of steps required to change string A to string B.
Constraints:
1 <= length(A), length(B), length(C[i]) <= 25
1 <= length(C) <= 5e3
Example :
Input 1:
A = "hit"
B = "cog"
C = ["hot", "dot", "dog", "lot", "log"]
Output 1: 5
Explanation 1: "hit" -> "hot" -> "dot" -> "dog" -> "cog"
**/
#include<bits/stdc++.h>
bool differByOne(string &s1, string &s2){
  int count=0;
  for(int i=0; i<s1.size(); i++){
    if(s1[i]!=s2[i]) count++;
  }
  if(count==1) return true;
  else return false;
}
int bfs(unordered_map<string, list<string>> &g, unordered_map<string, bool> &visited, string src, string des){
  int minDistance=0;
  if(src==des) return 0;
  queue<string> q;
  q.push(src);
  visited[src]=true;
  while(!q.empty()){
    int size= q.size();
    while(size--){
      auto node= q.front();
      q.pop();
      for(auto neighbour: g[node]){
        if(neighbour==des) return ++minDistance;
        if(!visited[neighbour]){
          q.push(neighbour);
          visited[neighbour]=true;
        }
      }
    }
    minDistance++;
  }
  return -1;
}
int Solution::solve(string A, string B, vector<string> &C){
  unordered_map<string, list<string>> g;
  unordered_map<string, bool> visited;
  C.push_back(A);
  for(int i=0; i<C.size(); i++){
    for(int j=i+1; j<C.size(); j++){
      if(differByOne(C[i], C[j])){
        g[C[i]].push_back(C[j]);
        g[C[j]].push_back(C[i]);
      }
    }
  }
  return bfs(g, visited, A, B)+1;
}
