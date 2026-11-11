cmake_minimum_required(VERSION 3.20)
project(ColaImpresion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cola main.cpp)
target_compile_options(cola PRIVATE -Wall -Wextra)
