/**
https://stackoverflow.com/questions/1326118/sum-of-square-of-each-elements-in-the-vector-using-for-each
**/
#include <bits/stdc++.h>
using namespace std;
static int sum = 0;
void add_f(int i ) {
  sum += i * i;
}
int main() {
  int arr[] = {1,2,3,4};
  std::vector<int> a (arr ,arr + sizeof(arr)/sizeof(arr[0]));
  int sum = 0;
  std::for_each(a.begin(), a.end(), [&](int i) { sum += i*i;} );
  std::for_each(a.begin(),a.end(), add_f);
  return 0;
}
