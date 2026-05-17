# CMakeLists.txt file

cmake_minimum_required(VERSION 3.14)
project(CodeChallengesCpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Habilitar el motor de pruebas de CMake (CTest)
enable_testing()

# Descargar Catch2 de forma automática desde GitHub
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com
  GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

# Pasar el control a la carpeta src
add_subdirectory(src)
