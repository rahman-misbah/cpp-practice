/*
 * File: bubble_sort.cpp
 * Date: 2026-01-21
 * 
 * Purpose: 
 *      Implements adaptive bubble sort.
 * 
 * Complexity: 
 *      Time: O(n^2) where n is the number of elements in the array
 *      Space: O(1)
 * 
 * Compilation:
 *      g++ -std=c++11 -o bubble_sort bubble_sort.cpp
 * 
 * Usage: 
 *      ./bubble_sort
 * 
 * Example: 
 *      $ ./bubble_sort
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

void bubble_sort(int arr[], int size) {
    bool swapped;

    for(int i = 0; i < size - 1; i++) {
        swapped = false;

        for(int j = 0; j < (size - 1 - i); j++) {
            if(arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped) {
            break;
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    bubble_sort(arr, size);

    std::cout << "Sorted array: \n";
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}