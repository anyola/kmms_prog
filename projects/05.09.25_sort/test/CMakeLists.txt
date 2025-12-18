add_executable(test_merge test_merge.cpp)
target_include_directories(test_merge PRIVATE ../src)

target_link_libraries(test_merge 
    merge_sort_lib  
    gtest 
    gtest_main
)

add_test(NAME test COMMAND test_merge)