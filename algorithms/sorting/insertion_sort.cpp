/*
 * File: insertion_sort.cpp
 * Date: 2026-01-21
 * 
 * Purpose: 
 *      Implements simple insertion sort.
 * 
 * Complexity: 
 *      Time: O(n^2) where n is the number of elements in the array
 *      Space: O(1)
 * 
 * Compilation:
 *      g++ -std=c++11 -o insertion_sort insertion_sort.cpp
 * 
 * Usage: 
 *      ./insertion_sort
 * 
 * Example: 
 *      $ ./insertion_sort
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

void insertion_sort(int arr[], int size) {
    int j, key;

    for(int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    insertion_sort(arr, size);

    std::cout << "Sorted array: \n";
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}