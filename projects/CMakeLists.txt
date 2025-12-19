cmake_minimum_required(VERSION 3.16)
project(Projects)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(lib/googletest)
enable_testing()

add_subdirectory(05.09.25_sort)
add_subdirectory(menu_task2)

