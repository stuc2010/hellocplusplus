add_library(HelloWorld helloworld.cpp)
target_include_directories(HelloWorld INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})