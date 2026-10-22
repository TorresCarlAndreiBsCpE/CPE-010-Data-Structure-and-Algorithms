#include "nodes.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

template <typename T>
void linearSearchArr(T data[], int arrSize, T dataFind){

    int i = 0;

    while(i < arrSize){
        if(dataFind == data[i]){
            std::cout<<"the search is success\n";
            return;
        }

        i++;
    }

    std::cout<< "the element is not found\n";
    return;
}

template <typename T>
void linearSearchLL (Node<T> *node, T dataFind){
    //Repeat the loop until the current node is not null
    while (node != nullptr){
    
    if(dataFind == node -> data){
        std::cout<<"the search is a success\n";
        return;
    }
    node = node -> next;
    }
    std::cout<<"The element is not found\n";
    return;
}

template <typename T>
Node<T>* getMiddleLL(Node<T>* start, Node<T>* last){
    if (start == nullptr) return nullptr;

    Node<T>* slow = start;
    Node<T>* fast = start;


    while(fast != last && fast -> next != last){
        //move slow (one step)
        slow = slow -> next;
        //move slow (two steps)
        fast = fast -> next -> next;
    }
    //when fast reaches the end
    // slow points to the middle node
    return slow;
}

template <typename T>
void binarySearchLL (Node<T> *start, T findData){
     Node<T>* low = start;
     Node<T>* up = nullptr;

    while (low != up && (low == nullptr || low -> next != up || low != up)){
        if (low == nullptr) break;

        Node<T>* mid = getMiddleLL(low, up);

        if (mid == nullptr) break;
        

        if (findData == mid -> data){
            std::cout << "Search element is found!" << std::endl;
            return;
        }
        else if (findData < mid -> data) {
            up = mid;
        } else {
            low = mid -> next;
        }
    }
    std::cout << "The Search Element is not found" << std::endl;
}

int getMiddleArr(int low, int up) {
    return (low + up) / 2;
}

template <typename T>
void binarySearchArr(T data[], int arrSize, T dataFind){

    int low = 0;
    int up = arrSize - 1;
    int mid = low + (up - low) / 2;

    while(low <= up) {
        int mid = getMiddleArr(low, up);

        if (dataFind == data[mid]) {
            std::cout << "The Search Element is found!" << std::endl;
            return;
        }
        else if (dataFind < data[mid]){
            up = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    std::cout<< "The Search Element is not found" << std::endl;
}



#endif