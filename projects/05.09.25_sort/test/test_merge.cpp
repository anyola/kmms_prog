#include <gtest/gtest.h> 
#include "merge_sort.hpp"

TEST(Array$Equal, AnyElementsCount) {
    int actual[] = {1, 8, 2, 5, 3, 11}; 
    int size = 6; 
    
    saa::merge_sort(actual, 0, size - 1);
    
    int expected[] = {1, 2, 3, 5, 8, 11};
    
    for (int i = 0; i < size; i++) { 
        ASSERT_EQ(expected[i], actual[i])
            << "Массив ожидаемый и отсортированный отличаются в элементе " << i; 
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}