/*
 * File: square_root.cpp
 * Date: 2026-01-11
 * 
 * Purpose: 
 *      Compute square root using binary search algorithm.
 *      Handles numbers >= 0 with configurable precision.
 * 
 * Complexity: 
 *      Time: O(log(max(1, n)/ε)) where ε is tolerance
 *      Space: O(1)
 * 
 * Compilation:
 *      g++ -std=c++11 -o square_root square_root.cpp
 * 
 * Usage: 
 *      ./square_root <number>          # With command-line argument
 *      ./square_root                   # Interactive mode
 * 
 * Example: 
 *      $ ./square_root 12.24
 *      3.49857
 * 
 *      $ ./square_root
 *      Enter a number (non-negative): 2
 *      1.41421
 * 
 * Dependencies: C++11 or later
 * 
 * Author: Misbahur Rahman
 * 
 * Limitations:
 *      - No iteration limit. Could loop infinitely for bad tolerance 
 *      - Doesn't handle leading and trailing spaces
 *      - Spaghetti code for input validation
 * 
 * Notes:
 *      - Precision below 1e-14 may not be possible due to double precision limits
 *      - For numbers < 1, sqrt(num) > num, so search in range (num, 1)
 */

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using std::string;

namespace math {
    // Can't take tolerance below 1e-14, machine limitations
    double sqrt(double num, double tolerance = 1e-14, size_t max_iter = 100);
}

double validate_double(string num_str);

int main(int argc, char* argv[]) {
    string num_str;
    double num;

    if(argc > 1) num_str = argv[1];
    else {
        std::cout << "Enter a number (non-negative): ";
        std::cin >> num_str;
    }

    num = validate_double(num_str);
    std::cout << math::sqrt(num) << std::endl;
    
    return EXIT_SUCCESS;
}

// Need to improve on validation logic for clarity and maintainibility.
// I'm sure a much better way exists, which I'll work on figuring out.
double validate_double(string num_str) {
    double num;
    size_t pos;

    try {
        num = std::stod(num_str, &pos);

        if(num_str.size() != pos) throw std::invalid_argument("");
        if(num < 0) throw std::invalid_argument("negative");
    } catch (const std::invalid_argument& e) {
        if(e.what() == "negative")
            std::cerr << "ERROR: " << num_str << " is a negative number" << std::endl;
        else
            std::cerr << "ERROR: " << num_str << " is not a valid number" << std::endl;
        exit(EXIT_FAILURE);
    }

    return num;
}

// TODO: Implement error handling for infinite loop in case of unchanging error
double math::sqrt(double num, double tolerance, size_t max_iter) {
    if(num < 0) return NAN;
    if(num == 0 || num == 1) return num;

    double low, high, mid;  // For binary search
    double mid_square, error = 1 + tolerance;
    size_t iter_count = 0;

    // If the number is less than 1, its square root lies between 0 and 1.
    // In any other case (except 1), the square root will be greater than 1.
    if(num < 1) {
        low = num;
        high = 1;
    } else {
        low = 1;
        high = num;
    }

    while(error > tolerance && iter_count < max_iter) {
        mid = low + (high - low) / 2;
        mid_square = mid * mid;
        error = std::abs(mid_square - num);

        if(mid_square > num) high = mid;
        else low = mid;

        iter_count++;
    }

    return mid;
}