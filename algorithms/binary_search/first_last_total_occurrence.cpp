/*
 * File: first_last_total_occurrence.cpp
 * Date: 2026-01-18
 * 
 * Purpose: 
 *      Find first occurrence, last occurrence, and total occurrences of a 
 *      target element in a sorted array using binary search.
 * 
 * Complexity: 
 *      Time: O(log n) where n is the number of elements in the array
 *      Space: O(1)
 * 
 * Compilation:
 *      g++ -std=c++11 -o first_last_total_occurrence first_last_total_occurrence.cpp
 * 
 * Usage: 
 *      ./first_last_total_occurrence
 * 
 * Example: 
 *     $ ./first_last_total_occurrence
 *     First Occurrence of 5: 6
 *     Last Occurrence of 5: 9
 *     Total Occurrence of 5: 4
 * 
 * Author: Misbahur Rahman
 * 
 * Todo:
 *      - Take input from user for array and target element
 *      - Extend to handle generic types using templates
 */

#include <iostream>

int first_occurrence(int arr[], int size, int target) {
    int mid;
    int left = 0;
    int right = size - 1;
    int result = -1;

    while(left <= right) {
        mid = left + (right - left) / 2;

        if(arr[mid] == target) {
            result = mid;
            right = mid - 1;    // Continue searching in the left half
        }
        else if(arr[mid] < target) {
            left = mid + 1;     // Search in the right half
        }
        else {
            right = mid - 1;    // Search in the left half
        }
    }

    return result;
}

int last_occurrence(int arr[], int size, int target) {
    int mid;
    int left = 0;
    int right = size - 1;
    int result = -1;

    while(left <= right) {
        mid = left + (right - left) / 2;

        if(arr[mid] == target) {
            result = mid;
            left = mid + 1;     // Continue searching in the right half
        }
        else if(arr[mid] < target) {
            left = mid + 1;     // Search in the right half
        }
        else {
            right = mid - 1;    // Search in the left half
        }
    }

    return result;
}

int total_occurrence(int arr[], int size, int target) {
    int first = first_occurrence(arr, size, target);

    if(first == -1) {
        return 0;   // Target not found
    }

    int last = last_occurrence(arr, size, target);

    return last - first + 1;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5, 5, 5, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    std::cout << "First Occurrence of " << target << ": " << first_occurrence(arr, size, target) << std::endl;
    std::cout << "Last Occurrence of " << target << ": " << last_occurrence(arr, size, target) << std::endl;
    std::cout << "Total Occurrence of " << target << ": " << total_occurrence(arr, size, target) << std::endl;

    return 0;
}