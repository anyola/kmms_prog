add_executable(test_merge test_merge.cpp)

target_link_libraries(test_merge 
    merge_sort_lib  
    gtest 
    gtest_main
)

add_test(NAME MergeSortTests COMMAND test_merge)