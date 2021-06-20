/**
https://www.interviewbit.com/old/problems/shortest-unique-prefix/
Find shortest unique prefix to represent each word in the list.
Example:
Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
NOTE : Assume that no word is prefix of another.
In other words, the representation is always possible. 
**/
struct TrieNode{
  char val;
  int count;
  int endsHere;
  TrieNode *child[26];
};
TrieNode *getNode(int index){
  TrieNode *newNode = new TrieNode;
  newNode->val = index+'a';
  newNode->count = newNode->endsHere=0;
  for(int i=0;i<26;i++)
    newNode->child[i]=NULL;
  return newNode;
}
void insert(TrieNode *root,string word){
  TrieNode *curr = root;
  int index;
  for(int i=0;i<word.size();i++){
    index = word[i]-'a';
    if(curr->child[index]==NULL)
      curr->child[index]=getNode(index);
    curr->child[index]->count++;
    curr = curr->child[index];
  }
  curr->endsHere++;
}
string searchPrefix(TrieNode *root , string word){
  TrieNode *curr = root;
  int index;
  string res="";
  char value;
  for(int i=0;i<word.size();i++){
    index = word[i]-'a';
    if(curr->child[index]->count>1){
      res += curr->child[index]->val;
    }
    else if(curr->child[index]->count==1){
      value = curr->child[index]->val;
      break;
    }
    curr = curr->child[index];
  }
  res += value;
  return res;
}
vector<string> Solution::prefix(vector<string> &A) {
  TrieNode *root = getNode('/'-'a');
  int i;
  vector<string>ans;
  for(i=0;i<A.size();i++){
    insert(root,A[i]);
  }
  for(i=0;i<A.size();i++){
    ans.push_back(searchPrefix(root,A[i]));
  }
  return ans;   
}
