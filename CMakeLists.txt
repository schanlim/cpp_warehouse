cmake_minimum_required(VERSION 3.10)

project(DesignPattern C CXX)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

enable_testing()
add_subdirectory(googletest)
add_subdirectory(example)
