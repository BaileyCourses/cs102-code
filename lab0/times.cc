#include <iostream>

float times(int x) {
    return 1.5 * x;
}

int main() {
    std::cout << "Give me a number to multiply by 1.5: ";

    int input = 0;
    std::cin >> input;
    std::cout << "1.5 * " << input << " = " << times(input) << std::endl;
    return 0;
}
