#include <iostream>

int main () {
    int num1, num2;

    std::cout << "Number 1: " ;
    std::cin >> num1;
    std::cout << "Number 2: " ;
    std::cin >> num2;

    std::cout << "Before the Swap: " << num1 << num2 << std::endl;
    std:: swap(num1, num2);
    std::cout << "After the Swap: " << num1 << num2 << std::endl;

    return 0;
}