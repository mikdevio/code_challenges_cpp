# 001_two_sum

# Crear el ejecutable de la prueba uniendo solución y test
add_executable(test_001_two_sum solution.cpp solution_test.cpp)

# Vincular con la librería base de pruebas y Catch2
target_link_libraries(test_001_two_sum PRIVATE tests_common_lib Catch2::Catch2)

# Registrar la prueba en CTest
add_test(NAME 001_two_sum COMMAND test_001_two_sum)

