# 001_greed_is_good

add_executable(test_001_greed_is_good solution.cpp solution_test.cpp)
target_link_libraries(test_001_greed_is_good PRIVATE tests_common_lib Catch2::Catch2)
add_test(NAME 001_greed_is_good COMMAND test_001_greed_is_good)
