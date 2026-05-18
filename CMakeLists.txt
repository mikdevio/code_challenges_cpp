# CMakeLists.txt file

cmake_minimum_required(VERSION 3.14)
project(CodeChallengesCpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Habilitar el motor de pruebas de CMake (CTest)
enable_testing()

# Buscar Catch2 instalado nativamente en Arch Linux
find_package(Catch2 3 REQUIRED)

# Pasar el control a la carpeta src
add_subdirectory(src)
