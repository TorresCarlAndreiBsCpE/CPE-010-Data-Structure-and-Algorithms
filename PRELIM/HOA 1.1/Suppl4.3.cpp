#include <iostream>
#include <cmath>

class Triangle {
private:

    double totalAngle, totalArea, totalPerimeter;
    double base, height;
    double angleA, angleB, angleC;
    double sideA, sideB, sideC;

public:
    //constructor
    Triangle(double A, double B, double C);

    //methods
    void setAngles(double A, double B, double C);
    void setArea(double Base, double Height);
    void displayArea() const;
    void setPerimeter(double A, double B, double C);
    void displayPerimeter() const;

    //validation
    bool validateTriangle() const;
    void classifyAngle() const;
    void displayAngle() const;
};

//Driver Code
int main() {
    Triangle set1(40, 30, 110);
    set1.setAngles(90,45,45);

    if(set1.validateTriangle()){
        std::cout<<"The figure is a valid Triangle"<<std::endl;

        set1.setArea(9, 6);
        set1.displayArea();

        set1.setPerimeter(9, 7, 8);
        set1.displayPerimeter();

        set1.displayAngle();
        set1.classifyAngle();
    } else {
        std::cout<<"The figure is NOT a valid Triangle. \n";
    }
return 0;
}
//Define
Triangle::Triangle(const double A, const double B, const double C)
    : totalAngle(0), totalArea(0), totalPerimeter(0),
      base(0), height(0),
      angleA(A), angleB(B), angleC(C),
      sideA(0), sideB(0), sideC(0){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
    totalArea = 0;
    totalPerimeter = 0;
}

void Triangle::setAngles(const double A, const double B, const double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}

void Triangle::setArea(const double Base, const double Height) {
    base = Base;
    height = Height;
    totalArea = 0.5 * base * height;
}

void Triangle::displayArea() const {
    std::cout << "The Area of the Triangle is: " << totalArea << std::endl;
}

void Triangle::setPerimeter(const double A, const double B, const double C) {
    sideA = A;
    sideB = B;
    sideC = C;
    totalPerimeter = A+B+C;
}

void Triangle::displayPerimeter() const {
    std::cout << "The Perimeter of the Triangle is: " << totalPerimeter << std::endl;
}

bool Triangle::validateTriangle() const {
    return (std::abs(totalAngle - 180) < 1e-6);
}
void Triangle::classifyAngle() const {
    if (!validateTriangle()) {
        std::cout << "Cannot classify the invalid triangle.\n";
    }
   if (angleA < 90 && angleB < 90 && angleC < 90) {
       std::cout << "The Triangle has an Acute Angle" << std::endl;
   } else if (angleA == 90 || angleB == 90 || angleC == 90) {
       std::cout << "The Triangle has an Right Angle" << std::endl;
   } else if (angleA > 90 || angleB > 90 || angleC > 90) {
       std::cout << "The Triangle has an Obtuse Angle" << std::endl;
   }
}
void Triangle::displayAngle() const {
    std::cout << "The Angle of the Triangle is: " << std::endl;
    std::cout << "Angle A: " << angleA << std::endl;
    std::cout << "Angle B: " << angleB << std::endl;
    std::cout << "Angle C: " << angleC << std::endl;
}