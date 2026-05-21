#include <catch2/catch_test_macros.hpp>
#include <vector>

// Case 1: "abcabcbb"
// Case 2: "bbbbb"
// Case 3: "pwwkew"

int lengthOfLongestSubstring(const std::vector<int>& arr);

TEST_CASE("Pruebas para 002_longest_substring_no_repeating", "[leetcode_problems]") {
    SECTION("Basic case") {
        std::vector<int> data = {1, 2, 3};
        REQUIRE(lengthOfLongestSubstring(data) == 0);
    }
}
