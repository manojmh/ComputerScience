#include <algortithm>
using namespace std;

template<typename T>
struct square {
  T operator()(const T& Left, const T& Right) const {
    return (Left + Right*Right);
  }
};
int main() {
  vector<int> v1 = {1,2,3,4,5};
  //sums all the elements in the array
  cout << accumulate( v1.begin(), v1.end(), 0);
  //sums all the elements in array +5 as the initial value
  cout << accumulate( v1.begin(), v1.end(), 5);
  //sum of sqaure of each element in an array
  cout << accumulate(v1.begin(), v1.end(), 0, square<int>());
  return 0;
}
