#!/usr/bin/env bash

if [ $# -lt 3 ]; then
    echo "Uso: $0 <plataforma> <id_nombre> <nombre_funcion>"
    echo "Ejemplo: $0 leetcode_problems 001_two_array_sum sumTwoArrays"
    exit 1
fi

PLATAFORMA=$1
RETO=$2
FUNCION=$3
# 👈 Ruta modificada para apuntar dentro de src
DIR="src/$PLATAFORMA/$RETO"
TARGET_CMAKE="src/CMakeLists.txt"

mkdir -p "$DIR"

# Generar solution.cpp
cat << 'EOF' > "$DIR/solution.cpp"
#include <vector>

int __FUNCION__(const std::vector<int>& arr) {
    return 0;
}
EOF
sed -i "s/__FUNCION__/$FUNCION/g" "$DIR/solution.cpp"

# Generar solution_test.cpp
cat << 'EOF' > "$DIR/solution_test.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

int __FUNCION__(const std::vector<int>& arr);

TEST_CASE("Pruebas para __RETO__", "[__PLATAFORMA__]") {
    SECTION("Caso Base") {
        std::vector<int> datos = {1, 2, 3};
        REQUIRE(__FUNCION__(datos) == 0);
    }
}
EOF
sed -i "s/__FUNCION__/$FUNCION/g" "$DIR/solution_test.cpp"
sed -i "s/__RETO__/$RETO/g" "$DIR/solution_test.cpp"
sed -i "s/__PLATAFORMA__/$PLATAFORMA/g" "$DIR/solution_test.cpp"

# Generar CMakeLists.txt local del reto
cat << EOF > "$DIR/CMakeLists.txt"
add_executable(test_${RETO} solution.cpp solution_test.cpp)
target_link_libraries(test_${RETO} PRIVATE tests_common_lib Catch2::Catch2)
add_test(NAME ${RETO} COMMAND test_${RETO})
EOF

# 👈 Registrar la ruta relativa en src/CMakeLists.txt
LINEA_CMAKE="add_subdirectory($PLATAFORMA/$RETO)"
if ! grep -Fxq "$LINEA_CMAKE" "$TARGET_CMAKE"; then
    echo "$LINEA_CMAKE" >> "$TARGET_CMAKE"
    echo "✅ Reto registrado con éxito en $TARGET_CMAKE."
fi

echo "🚀 Estructura creada exitosamente en: $DIR"
