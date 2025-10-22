#include <algorithm>
#include "merge_sort.hpp"

void sorting::merge(int* const arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* left_arr = new int[n1];
    int* right_arr = new int[n2];

    for(int i = 0; i < n1; i++) {
        left_arr[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++) {
        right_arr[j] = arr[mid + j + 1];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while(i < n1 && j < n2) {
        if(left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        }
        else{
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
    delete[] left_arr;
    delete[] right_arr;
}

void sorting::merge_sort(int arr[], int left, int right) {
    if(left < right){
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}