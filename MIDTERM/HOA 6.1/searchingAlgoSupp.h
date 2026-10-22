#ifndef SEARCHINGALGOSUPP_H
#define SEARCHINGALGOSUPP_H

#include <iostream>
#include "nodesSupp.h"

//Helper Functions
int getMiddleArr(int low, int high) {
    return low + (high - low) / 2;
}

template <typename T>
Node<T>* getMiddleLL(Node<T>* start, Node<T>* last) {
    Node<T>* slow = start;
    Node<T>* fast = start;
    while (fast != last && fast->next != last) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//Linear Search Functions
template <typename T>
void linearSearchArr(T data[], int arrSize, T dataFind) {
    int counter = 0;
    for (int i = 0; i < arrSize; i++) {
        counter++;
        if (data[i] == dataFind) {
            std::cout << "Search Success\n";
            std::cout << "Comparison Count: " << counter << "\n";
            return;
        }
    }
    std::cout << "Element not found\nComparison Count: " << counter << "\n";
}

template <typename T>
void linearSearchLL(Node<T>* node, T dataFind) {
    int counter = 1;
    while (node != nullptr) {
        if (node->data == dataFind) {
            std::cout << "Search Success\n";
            std::cout << "Comparison Count: " << counter << "\n";
            return;
        }
        node = node->next;
        counter++;
    }
    std::cout << "Element not found\nComparison Count: " << counter - 1 << "\n";
}

//Modified Linear Search (Count Occurrences)
template <typename T>
void linearSearchArrMOD(T data[], int arrSize, T dataFind) {
    int i = 0;
    int counter = 0;
    while (i < arrSize) {
        if (data[i] == dataFind) {
            counter++;
        }
        i++;
    }
    std::cout << "Count: " << counter << "\n";
}

template <typename T>
void linearSearchLLMOD(Node<T>* node, T dataFind) {
    int counter = 0;
    while (node != nullptr) {
        if (node->data == dataFind) {
            counter++;
        }
        node = node->next;
    }
    std::cout << "Count: " << counter << "\n";
}

//Iterative Binary Search
template <typename T>
void binarySearchArr(T data[], int arrSize, T dataFind) {
    int low = 0;
    int high = arrSize - 1;
    while (low <= high) {
        int middle = getMiddleArr(low, high);
        if (data[middle] == dataFind) {
            std::cout << "Search Success\n";
            return;
        } else if (data[middle] > dataFind) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
    std::cout << "Search Failed\n";
}

template <typename T>
void binarySearchLL(Node<T>* head, T dataFind) {
    Node<T>* start = head;
    Node<T>* last = nullptr;
    while (start != last) {
        Node<T>* middle = getMiddleLL(start, last);
        if (middle == nullptr) break;
        
        if (middle->data == dataFind) {
            std::cout << "Search Success\n";
            return;
        } else if (middle->data > dataFind) {
            last = middle;
        } else {
            start = middle->next;
        }
    }
    std::cout << "Search Failed\n";
}

//Recursive Binary Search
template <typename T>
void binarySearchArrMOD(T data[], int arrSize, T dataFind, int low, int high) {
    if (low <= high) {
        int middle = getMiddleArr(low, high);
        if (data[middle] == dataFind) {
            std::cout << "Search Success\n";
            return;
        } else if (data[middle] > dataFind) {
            high = middle - 1;
            binarySearchArrMOD(data, arrSize, dataFind, low, high);
            return;
        } else {
            low = middle + 1;
            binarySearchArrMOD(data, arrSize, dataFind, low, high);
            return;
        }
    }
    std::cout << "Search Failed\n";
}

#endif