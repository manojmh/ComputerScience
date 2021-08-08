/**
Performance of Chaining: 
Performance of hashing can be evaluated under the assumption that each key is equally likely to be hashed to any slot of table (simple uniform hashing).  
m = Number of slots in hash table
n = Number of keys to be inserted in hash table
Load factor α = n/m 
Expected time to search = O(1 + α)
Expected time to delete = O(1 + α)
Time to insert = O(1)
Time complexity of search insert and delete is 
O(1) if  α is O(1)

Data Structures For Storing Chains: 
Linked lists
Search: O(l) where l = length of linked list
Delete: O(l)
Insert: O(l)
Not cache friendly

Dynamic Sized Arrays ( Vectors in C++, ArrayList in Java, list in Python)
Search: O(l) where l = length of array
Delete: O(l)
Insert: O(l)
Cache friendly

Self Balancing BST ( AVL Trees, Red Black Trees)
Search: O(log(l))
Delete: O(log(l))
Insert: O(l)
Not cache friendly

Java 8 onwards use this for HashMap
**/
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class HashMap {
  int BUCKET;
  list<int> *hash;
  int hashFunc(int k) {
    return k%BUCKET;
  }
public:
  HashMap(int V){
    BUCKET = V;
    hash = new list<int>[BUCKET];
  }
  void insertItem(int k) {
    int idx = hashFunc(k);
    hash[idx].push_back(k);
  }
  void searchItem(int k) {
    int idx = hashFunc(k);
    for(auto it=hash[idx].begin(); it!=hash[idx].end(); ++it) {
      if(*it == k) {
        cout << "Key found at hash : " << idx << "\n";
        return;
      }
    }
    cout << "No key found\n";
  }
  void deleteItem(int k) {
    int idx = hashFunc(k);
    auto it = find(hash[idx].begin(), hash[idx].end(), k);
    if(it!=hash[idx].end()) {
      hash[idx].erase(it);
    }
  }
  void displayHash() {
    for(int i=0; i<BUCKET; ++i) {
      cout << i << " ";
      for(auto v : hash[i]) {
        cout << "-->" << v;
      }
      cout << endl;
    }
  }
};

int main() {
  int a[] = {15, 11, 27, 8, 12};
  int n = sizeof(a)/sizeof(a[0]);
  HashMap h(7);
  for (int i = 0; i < n; i++) 
    h.insertItem(a[i]);
  h.displayHash();
  cout << endl;
  h.deleteItem(15);
  h.displayHash();
  return 0;
}
