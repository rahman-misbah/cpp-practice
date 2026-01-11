/*
 * File: prime_checker.cpp
 * Date: 2026-01-10
 * Purpose: Checks if a number is prime. Can accept argument from command line.
 * Complexity: O(log n), O(1)
 * Compilation: g++ -std=c++11 -o prime_checker prime_checker.cpp
 * Usage: ./prime_checker <number> or ./prime_checker
 * Example: ./prime_checker 17 -> "17 is a prime"
 * Author: Misbahur Rahman
 */

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using std::string;

bool isPrime(int n);

int main(int argc, char* argv[]) {
    string num_str;
    int num;
    size_t pos;

    // Check command line argument
    if(argc > 1) num_str = argv[1];
    else {
        std::cout << "Enter an integer: ";
        std::cin >> num_str;
    }
    
    // Validate input
    try {
        num = std::stoi(num_str, &pos);

        if(pos != num_str.size()) {
            std::cerr << "ERROR: " << num_str << " is not a valid integer" << std::endl;
            return EXIT_FAILURE;
        }
    } catch (const std::invalid_argument&) {
        std::cerr << "ERROR: " << num_str << " is not a valid integer" << std::endl;
        return EXIT_FAILURE;
    } catch (const std::out_of_range&) {
        std::cerr << "ERROR: " << num_str << " is out of integer range" << std::endl;
        return EXIT_FAILURE;
    }


    if(isPrime(num)) std::cout << num << " is a prime" << std::endl;
    else std::cout << num << " is not a prime" << std::endl;

    return EXIT_SUCCESS;
}

bool isPrime(int n) {
    if(n < 2) return false;

    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    
    return true;
}