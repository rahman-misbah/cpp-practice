/*
 * File: bitonic_sequence_peak.cpp
 * Date: 2026-01-18
 * 
 * Purpose: 
 *      Finds the peak index in a bitonic sequence using binary search.
 *      Assumes the input array is bitonic (first strictly increasing then strictly decreasing).
 * 
 * Complexity: 
 *      Time: O(log n) where n is the number of elements in the array
 *      Space: O(1)
 * 
 * Compilation:
 *      g++ -std=c++11 -o bitonic_sequence_peak bitonic_sequence_peak.cpp
 * 
 * Usage: 
 *      ./bitonic_sequence_peak
 * 
 * Example: 
 *     $ ./bitonic_sequence_peak
 *     Peak index: 3, Peak value: 12
 * 
 * Author: Misbahur Rahman
 * 
 * Todo:
 *      - Take input from user for array and target element
 *      - Verify input array is bitonic
 */

#include <iostream>

int peak_index(int arr[], int size) {
    if(size < 3) return -1;  // A bitonic array must have at least 3 elements

    int mid;
    int left = 0;
    int right = size - 1;
    
    while(left <= right) {
        mid = left + (right - left) / 2;

        if(mid + 1 < size && arr[mid] < arr[mid + 1]) {
            // mid is in the ascending part of the array
            // Move right
            left = mid + 1;
        }
        else if(mid - 1 >= 0 && arr[mid] < arr[mid - 1]) {
            // mid is in the descending part of the array
            // Move left
            right = mid - 1;
        }
        else {
            // mid is the peak
            return mid;
        }
    }

    return -1;  // Peak not found (should not happen in a valid bitonic array)
}

int main() {
    int arr[] = {1, 3, 8, 12, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int peak = peak_index(arr, size);

    if(peak != -1) {
        std::cout << "Peak index: " << peak << ", Peak value: " << arr[peak] << std::endl;
    } else {
        std::cout << "No peak found in the array." << std::endl;
    }

    return 0;
}