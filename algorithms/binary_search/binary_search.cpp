/*
 * File: binary_search.cpp
 * Date: 2026-01-18
 * 
 * Purpose: 
 *      Implement binary search algorithm to find an element in a sorted array.
 * 
 * Complexity: 
 *      Time: O(log n) where n is the number of elements in the array
 *      Space: O(1)
 * 
 * Compilation:
 *      g++ -std=c++11 -o binary_search binary_search.cpp
 * 
 * Usage: 
 *      ./binary_search
 * 
 * Example: 
 *     $ ./binary_search
 *     Element found at index: 3
 * 
 * Author: Misbahur Rahman
 * 
 * Todo:
 *      - Take input from user for array and target element
 *      - Extend to handle generic types using templates
 */

#include <iostream>

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        // Mathemantically equivalent to (left + right) / 2
        // Numerically stable to prevent overflow

        if (arr[mid] == target) {
            return mid; // Target found
        }
        else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        }
        else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = binary_search(arr, size, target);

    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
