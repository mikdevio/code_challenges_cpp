// 001_two_sum solution_test.cpp

#include <catch2/catch_test_macros.hpp>
#include <vector>

// Function declaration
int sumTwo(const std::vector<int>& arr1, const std::vector<int>& arr2);

TEST_CASE("Sum two arrays", "[codeforces][001]"){
  SECTION("Array with positive values") {
    std::vector<int> a = {1,2,3};
    std::vector<int> b = {4,5};
    REQUIRE(sumTwo(a, b) == 15);
  }

  SECTION("Empty arrays"){
    std::vector<int> a = {};
    std::vector<int> b = {};
    REQUIRE(sumTwo(a, b) == 0);
  }

  SECTION("Inverse arrays"){
    std::vector<int> a = {4,5,6};
    std::vector<int> b = {6,5,4};
    REQUIRE(sumTwo(a, b) == 30);
  }
}
