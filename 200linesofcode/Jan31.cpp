#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
T findMin(const std::vector<T>& vec) { //a template function that can be applied to vectors of different data types
  if (vec.empty()) {
    throw std::invalid_argument("Cannot find minimum in this vector");
  }
  
  return *std::min_element(vec.begin(), vec.end()); //min_element returns a pointer so need to dereference
}

//unit test
int main() {
  std::vector<int> ints = {4, 7, 2, 8, 5};
  int min = findMin(ints);
  std::cout << "The smallest integer in here is: " << min << std::endl;

  std::vector<std::string> strings = {"options", "futures", "forwards"};
  std::string smallestString = findMin(strings);
  std::cout << "You can even find the smallest std::string: " << smallestString << std::endl;

  return 0;
}

