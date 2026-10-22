#include <iostream>
#include <cstdlib>
#include <time.h>
#include "nodes.h"
#include "searchingAlgo.h"


//Linear and Binary Search for Array
const int max_size = 50;

int main(){

    int dataset[max_size];
    srand(time(0));
    for(int i = 0; i<max_size; i++){
        dataset[i] = rand();
    }
    
    for (int i = 0; i < max_size; i++){
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;

    int toFind = dataset[0];
    std::cout<< "What value you want to search? ";
    std::cin >> toFind;

    std::cout << "Linear Search for Array Results: ";
    linearSearchArr(dataset, max_size, toFind);
    std::cout << "Binary Search for Array Results: ";
    binarySearchArr(dataset, max_size, toFind);

    //Linear and Binary Search for Linked List
    Node<char>* name1 = new_node('J');
    Node<char>* name2  = new_node('I');
    Node<char>* name3  = new_node('M');
    Node<char>* name4  = new_node('L');
    Node<char>* name5  = new_node('O');
    Node<char>* name6  = new_node('R');
    Node<char>* name7  = new_node('D');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;
    
    std::cout<<"Linear Search for Linked List Result: ";
    linearSearchLL(name1, 'D');
    std::cout<<"Linear Search for Linked List Result: ";
    linearSearchLL(name1, 'x');
    
    std::cout<<"Binary Search for Linked List Result: ";
    binarySearchLL(name1, 'J');
    std::cout<<"Binary Search for Linked List Result: ";
    binarySearchLL(name1, 'C');
}