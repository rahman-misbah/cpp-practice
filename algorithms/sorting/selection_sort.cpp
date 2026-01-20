/*
 * File: selection_sort.cpp
 * Date: 2026-01-20
 * 
 * Purpose: 
 *      Implements simple selection sort.
 * 
 * Complexity: 
 *      Time: O(n^2) where n is the number of elements in the array
 *      Space: O(1)
 * 
 * Compilation:
 *      g++ -std=c++11 -o selection_sort selection_sort.cpp
 * 
 * Usage: 
 *      ./selection_sort
 * 
 * Example: 
 *      $ ./selection_sort
 *      Sorted array:
 *      11 12 22 25 64
 * 
 * Author: Misbahur Rahman
 * 
 * Todo:
 *      - Take input from user for array and target element
 *      - Extend to handle generic types using templates
 */

#include <iostream>

void selection_sort(int arr[], int size) {
    int min_idx;

    for(int i = 0; i < size - 1; i++) {
        min_idx = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        if(min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    selection_sort(arr, size);

    std::cout << "Sorted array: \n";
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}