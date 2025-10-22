#include <iostream>
#include "io.hpp"

void saa::print_array(const char* const comment, int* arr, const int size) {
	std::cout << comment << '\n';
	for(int i =0; i < size; i++){
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}