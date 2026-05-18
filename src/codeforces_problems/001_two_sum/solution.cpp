// 001_two_sum solution.cpp

#include <vector>

int sumTwo(const std::vector<int>& arr1, const std::vector<int>& arr2) {
  int sum = 0;
  for(int n: arr1) sum += n;
  for(int n: arr2) sum += n;
  return sum;
}
