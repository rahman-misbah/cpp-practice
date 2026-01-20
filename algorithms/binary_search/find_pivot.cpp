/*
 * File: find_pivot.cpp
 * Date: 2026-01-20
 * 
 * Purpose: 
 *      Finds pivot element in a rotated sorted array of distinct items.
 * 
 * Complexity: 
 *      Time: O(log n) where n is the number of elements in the array
 *      Space: O(1)
 * 
 * Compilation:
 *      g++ -std=c++11 -o find_pivot find_pivot.cpp
 * 
 * Usage: 
 *      ./find_pivot
 * 
 * Example: 
 *     $ ./find_pivot
 *     Pivot index: 2
 * 
 * Author: Misbahur Rahman
 * 
 * Notes:
 *      The pivot is defined as the index of the smallest element in the rotated sorted array.
 *      
 * Todo:
 *      - Take input from user for array and target element
 */
#include <iostream>

int find_pivot(int arr[], int size) {
    // Pivot will always be smaller or equal to the mid element in a rotated sorted array
    // Since the first `if` guarantees that there is a smaller element in the right half, we can safely move low to mid + 1
    // However, if the mid element is smaller than the last element, we cannot rule out the possibility of the pivot being at mid
    int low = 0;
    int high = size - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] > arr[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    int arr[] = {8, 9, 1, 2, 3, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Pivot index: " << find_pivot(arr, size) << std::endl;
    return 0;
}