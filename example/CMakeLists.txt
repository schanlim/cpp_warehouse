cmake_minimum_required(VERSION 3.10)

set(lib_name example)

set(Headers
    Example.hpp
)
set(Sources
    Example.cpp
)
add_library(${lib_name} SHARED ${Sources} ${Headers})
add_subdirectory(tests)