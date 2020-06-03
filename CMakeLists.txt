cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Hello)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory("${PROJECT_SOURCE_DIR}/src/lib/HelloWorld")

# Set the executable
add_executable(Hello ./src/hello.cpp)

target_link_libraries(Hello PUBLIC HelloWorld)

target_include_directories(Hello PUBLIC "${PROJECT_BINARY_DIR}")

install(TARGETS Hello DESTINATION "${PROJECT_SOURCE_DIR}/dist")