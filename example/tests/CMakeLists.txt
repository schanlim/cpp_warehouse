cmake_minimum_required(VERSION 3.10)

set(TestName ExampleTests)
set(Sources
    ExampleTests.cpp
)   
add_executable(${TestName} ${Sources})
target_link_libraries(${TestName} gtest_main example)
add_test(
    NAME ${TestName}
    COMMAND ${TestName}
)