#include <iostream>

class Triangle{
private:
    double totalAngle, angleA, angleB, angleC;
public:
    //constructor
    Triangle(double A, double B, double C);

    //methods
    void setAngles(double A, double B, double C);

    //validation
    const bool validateTriangle();
};

//Driver Code
int main(){

    Triangle set1(40,30,110);
    if(set1.validateTriangle()){
        std::cout<<"The figure is a valid Triangle"<<std::endl;
    }else{
        std::cout<<"The figure is NOT a valid Triangle. \n";
    }

    return 0;
}

//Define
Triangle::Triangle(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}

void Triangle::setAngles(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}

const bool Triangle::validateTriangle(){
    return (totalAngle <= 180);
}