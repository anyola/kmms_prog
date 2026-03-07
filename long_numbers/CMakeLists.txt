cmake_minimum_required(VERSION 3.10)
project(long_numbers)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_subdirectory(googletest)

enable_testing()
add_subdirectory(test)