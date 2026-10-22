#include <iostream>

bool lgxop(bool one, bool two);

int main () {
    bool one, two;

    std::cout << "Enter 2 Values to be Calculated: "<<std::endl;
    std::cout << "Enter the First Number/Value: ";
    std::cin >> one;
    std::cout << "Enter the Second Number/Value: ";
    std::cin >> two;

    lgxop(one, two);
    return 0;
}
bool lgxop(bool one, bool two) {
    std :: cout << "For AND: " << (one && two) << std::endl;
    std :: cout << "For OR: " << (one || two) << std::endl;
    std :: cout << "For NOT of Value 1: " << (one != two) << std::endl;
    std :: cout << "For NOT of Value 2: " << (one != two) << std::endl;

    return true;
}