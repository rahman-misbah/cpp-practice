/*
 * File: 
 * Date: 
 * Purpose: Generate nth fibonacci number. Can accept command line argument.
 * Features: Uses the iterative approach [O(n), O(1)]
 * Compilation: g++ -std=c++11 -o prime_checker prime_checker.cpp
 * Usage: 
 * Example: 
 * Author: Misbahur Rahman
 */

#include <iostream>
#include <string>
#include <cstdlib>

using std::string;

int fibonacci(int n);

int main(int argc, char* argv[]) {
    string input;
    int n;
    size_t pos;

    if(argc > 1) input = argv[1];
    else {
        std::cout << "Enter term number (n): ";
        std::cin >> input;
    }

    // Input validation
    try {
        n = std::stoi(input, &pos);

        if(pos != input.size()) {
            std::cerr << "ERROR: " << input << " is not a valid integer" << std::endl;
            return EXIT_FAILURE;
        }
        if(n < 1) {
            std::cerr << "ERROR: Input must be greater than 0. " << input << " is not greater than 0" << std::endl;
            return EXIT_FAILURE;
        }
    } catch (const std::invalid_argument&) {
        std::cerr << "ERROR: " << input << " is not a valid integer" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << fibonacci(n) << std::endl;

    return EXIT_SUCCESS;
}

int fibonacci(int n) {
    int currentTerm = 0, nextTerm = 1;
    int temp;

    // Since first term is already initialized (0), loop is needed from second term onwards
    for(int i = 2; i <= n; i++) {
        temp = currentTerm;
        currentTerm = nextTerm;
        nextTerm = temp + currentTerm;
    }

    return currentTerm;
}