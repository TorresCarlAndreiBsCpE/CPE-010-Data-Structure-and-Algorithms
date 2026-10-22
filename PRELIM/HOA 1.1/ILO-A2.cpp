#include <iostream>

bool greaterThan(int a, int b);

int main() {
    int num1, num2;
    std::cout << "Enter the two numbers to compare: ";
    std::cin >> num1 >> num2;

    if (greaterThan(num1, num2)) {
        std::cout << num1 << " is greater than " << num2 << std::endl;
    } else {
        std::cout << num1 << " is not greater than " << num2 << std::endl;
    }
    return 0;
}

bool greaterThan(int a, int b) {
    return a > b;
}