cmake_minimum_required(VERSION 3.8)

set(This HelloTests)

set(Sources
    helloworld_tests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC 
    gtest_main
    HelloWorld
)

add_test(
    NAME ${This}
    COMMAND ${This}
)