#include <iostream>
#include <cmath>

//Function Prototype
double distanceBetweenTwoPoints(double x1, double y1, double x2, double y2);

//Main Function
int main() {
    double x1, y1, x2, y2;
    std::cout << "Enter the needed coordinates (x1, y1, x2, y2): " << std :: endl;
    std::cout << "x1 = ";
    std::cin >> x1;
    std::cout << "y1 = ";
    std::cin >> y1;
    std::cout << "x2 = ";
    std::cin >> x2;
    std::cout << "y2 = ";
    std::cin >> y2;

    std::cout << "The Distance Between the Two Points is: " << distanceBetweenTwoPoints(x1, y1, x2, y2) << std::endl;
    return 0;
}

//Define Function
double distanceBetweenTwoPoints(const double x1, const double y1, const double x2, const double y2) {
    const double distance = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    return distance;

}