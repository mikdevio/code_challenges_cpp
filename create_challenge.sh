#!/usr/bin/env bash

if [ $# -lt 3 ]; then
    echo "Usage: $0 <plataform> <id_name> <function_name>"
    echo "Example: $0 leetcode_problems 001_two_array_sum sumTwoArrays"
    exit 1
fi

PLATFORM=$1
CHALLENGE=$2
FUNCTION=$3
# 👈 Ruta modificada para apuntar dentro de src
DIR="src/$PLATFORM/$CHALLENGE"
TARGET_CMAKE="src/CMakeLists.txt"

mkdir -p "$DIR"

# Generate solution.cpp
cat << 'EOF' > "$DIR/solution.cpp"
#include <vector>

int __FUNCTION__(const std::vector<int>& arr) {
    return 0;
}
EOF
sed -i "s/__FUNCTION__/$FUNCTION/g" "$DIR/solution.cpp"

# Generate solution_test.cpp
cat << 'EOF' > "$DIR/solution_test.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

int __FUNCTION__(const std::vector<int>& arr);

TEST_CASE("Pruebas para __CHALLENGE__", "[__PLATFORM__]") {
    SECTION("Basic case") {
        std::vector<int> data = {1, 2, 3};
        REQUIRE(__FUNCTION__(data) == 0);
    }
}
EOF
sed -i "s/__FUNCTION__/$FUNCTION/g" "$DIR/solution_test.cpp"
sed -i "s/__CHALLENGE__/$CHALLENGE/g" "$DIR/solution_test.cpp"
sed -i "s/__PLATFORM__/$PLATFORM/g" "$DIR/solution_test.cpp"

# Generarte CMakeLists.txt local challenge
cat << EOF > "$DIR/CMakeLists.txt"
add_executable(test_${CHALLENGE} solution.cpp solution_test.cpp)
target_link_libraries(test_${CHALLENGE} PRIVATE tests_common_lib Catch2::Catch2)
add_test(NAME ${CHALLENGE} COMMAND test_${CHALLENGE})
EOF

# 👈 Register src/CMakeLists.txt
LINE_CMAKE="add_subdirectory($PLATFORM/$CHALLENGE)"
if ! grep -Fxq "$LINE_CMAKE" "$TARGET_CMAKE"; then
    echo "$LINE_CMAKE" >> "$TARGET_CMAKE"
    echo "✅ Challenge generated successfully in $TARGET_CMAKE."
fi

echo "🚀 Challenge created successfully on: $DIR"
