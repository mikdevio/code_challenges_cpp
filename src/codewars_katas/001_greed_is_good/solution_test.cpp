/* 001_greed_is_good solution_test.cpp */

#include <catch2/catch_test_macros.hpp>
#include <array>

int score(const std::array<unsigned, 5>& dice);

 // Throw       Score
 // ---------   ------------------
 // 5 1 3 4 1   250:  50 (for the 5) + 2 * 100 (for the 1s)
 // 1 1 1 3 1   1100: 1000 (for three 1s) + 100 (for the other 1)
 // 2 4 4 5 4   450:  400 (for three 4s) + 50 (for the 5)

TEST_CASE("Test for 001_greed_is_good", "[codewars_katas]") {
    SECTION("Basic case") {
        std::array<unsigned, 5> data = {5, 1, 3, 4, 1};
        REQUIRE(score(data) == 250);
    }

    SECTION("Second test") {
        std::array<unsigned, 5> data = {1, 1, 1, 3, 1};
        REQUIRE(score(data) == 1100);
    }

    SECTION("Third case") {
        std::array<unsigned, 5> data = {2, 4, 4, 5, 4};
        REQUIRE(score(data) == 450);
    }
}
