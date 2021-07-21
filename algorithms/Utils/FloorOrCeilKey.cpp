/**
Algorithm
There's really no need to search for an exactly matching key if we then go on to call lower_bound() - we could just call upper_bound() instead,
which will find the first key that's strictly greater than key, then decrement (if doing so is valid) to get the result:
auto it = input.upper_bound(key);
return it == input.begin()
    ? -1
    : (--it)->first;
Note that we have a problem here: if Key isn't a signed numeric type, then we can't return -1.
We really need a type-dependent value for this. Better still, return a std::optional, so a defaulted value can be clearly distinguished from an actual result.
**/
#include <map>
#include <optional>
template<typename Key, typename Value>
std::optional<Key> floorKey(const std::map<Key,Value>& input, const Key& key) {
  if (auto it = input.upper_bound(key);  it != input.begin()) {
    return (--it)->first;
  } else {
    return std::nullopt; //-1;
  }
}
std::optional<Key> ceilKey(const std::map<Key,Value>& input, const Key& key) {
  if (auto it = input.upper_bound(key);  it != input.end()) {
    return it->first;
  } else {
    return std::nullopt; //-1;
  }
}
#include <iostream>
int main(){
  std::map<int, int> map =
    {
     { 10, 100 },
     { 20, 200 },
     { 30, 300 },
     { 40, 400 },
     { 50, 500 },
     { 60, 600 },
     { 70, 700 },
     { 80, 800 },
    };
    std::cout << floorKey(map, 5).value_or(-1) << '\n'
            << floorKey(map, 9).value_or(-1) << '\n'
            << floorKey(map, 10).value_or(-1) << '\n'
            << floorKey(map, 11).value_or(-1) << '\n'
            << floorKey(map, 90).value_or(-1) << '\n';
}
