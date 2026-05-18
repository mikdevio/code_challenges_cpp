# CMakeLists.txt file

add_library(tests_common_lib STATIC main_test.cpp)
target_link_libraries(tests_common_lib PUBLIC Catch2::Catch2)
