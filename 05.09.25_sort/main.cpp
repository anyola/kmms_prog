#include "io.hpp"
#include "merge_sort.hpp"

int main() {
    int arr[] = {1, 8, 2, 5, 3, 11};
	const int arr_size = sizeof(arr) / sizeof(arr[0]);

	biv::print_array("Массив до сортировки:", arr, arr_size);
    
    biv::sorting::merge_sort(arr, 0, arr_size-1);

    biv::print_array("Массив после сортировки:", arr, arr_size);

    return 0;
}