#include <catch2/catch_test_macros.hpp>
#include <string>

#include "solution.h"

// Case 1: "abcabcbb"
// Case 2: "bbbbb"
// Case 3: "pwwkew"


TEST_CASE("Prueba 1 002_longest_substring_no_repeating", "[leetcode_problems]") {
    SECTION("Basic case") {
        Solution solver;
        std::string s = "abcabcbb";
        REQUIRE(solver.lengthOfLongestSubstring(s) == 3);
    }
}

TEST_CASE("Pruebas 2 002_longest_substring_no_repeating", "[leetcode_problems]") {
    SECTION("Basic case") {
        Solution solver;
        std::string s = "bbbbb";
        REQUIRE(solver.lengthOfLongestSubstring(s) == 1);
    }
}

TEST_CASE("Prueba 3 002_longest_substring_no_repeating", "[leetcode_problems]") {
    SECTION("Basic case") {
        Solution solver;
        std::string s = "pwwkew";
        REQUIRE(solver.lengthOfLongestSubstring(s) == 3);
    }
}
