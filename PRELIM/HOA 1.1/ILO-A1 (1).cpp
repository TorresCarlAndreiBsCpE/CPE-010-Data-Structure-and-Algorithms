#include <iostream>

int sumofTwoNumbers (int  fnum, int lnum);


int main() {
    std::cout<<sumofTwoNumbers(6, 9)<<std::endl;

    return 0;
}

int sumofTwoNumbers (int fnum, int lnum){
    int total = fnum + lnum;
    return total;
}
