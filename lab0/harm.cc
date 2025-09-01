/**
 * CS-102 Lab 01: Calculates the harmonic mean of two given numbers.
 * @file harm.cc
 * @author Dave Perkins
 * @collaborators Darren Strash, Alistair Campbell, Mark Bailey, Tom Helmuth
 * @date January 16, 2023
 */

#include <iostream>

/**
 * Returns the harmonic mean of two given numbers.
 * @param x the first number
 * @param y the second number
 * @return The harmonic mean of the given numbers.
 */
double harmonic_mean(double x, double y) {
    return (2 * x * y) / (x + y);
}

// Controls operation of the program.
int main() {
    double value1 = 0.0;
    double value2 = 0.0;

    std::cout << "Please enter a number: ";
    std::cin >> value1;
    std::cout << "Please enter another number: ";
    std::cin >> value2;

    const double result = harmonic_mean(value1, value2);

    std::cout << "The harmonic mean is: " << result << std::endl;

    return 0;
}
