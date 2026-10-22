#include <iostream>
#include <queue>

void display(std::queue<char> r);

int main(){

    std::queue<char> q;

    q.push('c');
    q.push('p');
    q.push('e');
    q.push('0');
    q.push('1');
    q.push('0');

    //Display
    display(q);

    //empty()
    std::cout<<"Is the stack Empty? "<<q.empty()<<std::endl;
    //size()
    std::cout<<"The size of the queue is: " << q.size() <<std::endl;

    //front
    std::cout<<"The front of the queue is: " << q.front()<<std::endl;

    //back
    std::cout<<"The back of the queue is: " <<q.back()<<std::endl;

    //pop
    q.pop();

    //display
    display(q);

    //push another element
    q.push('C');
    q.push('A');
    q.push('R');
    q.push('L');
    
    //display
    display(q);
}

void display(std::queue<char> r){
    //Create a copy of the queue
    std::queue<char> c = r;

    while(!c.empty()){
        std::cout<<" "<<c.front();
        c.pop();
    }
    std::cout<<"\n";
}