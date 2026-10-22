#include <iostream>
#include "queuell.h"

int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    std::cout<<"---ENQUEUE---\n";
    enqueue(&front, &back, 'C');
    std::cout<< front -> data << " " << back -> data << " " << std::endl;
    enqueue(&front, &back, 'A');
    std::cout<< front -> data << " " << back -> data << " " << std::endl;
    enqueue(&front, &back, 'T');
    std::cout<< front -> data << " " << back -> data << " " << std::endl;
    std::cout<<"---DEQUEUE---\n";
    dequeue(&front, &back);
    std::cout<< front -> data << " " << back -> data << " " << std::endl;
    std::cout<<"---DISPLAY LIST---\n";
    display(&front, &back);
    std::cout<<"---DISPLAY FRONT---\n";
    std::cout<< "The Front of the Queue is: " << FrontQ(front) << "\n";


    return 0;

}