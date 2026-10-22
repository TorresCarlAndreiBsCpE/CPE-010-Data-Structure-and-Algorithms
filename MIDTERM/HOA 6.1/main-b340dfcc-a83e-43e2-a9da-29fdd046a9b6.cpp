#include <iostream>
#include "nodesSupp.h"
#include "searchingAlgoSupp.h"

const int size = 10;

int main() {
    // Problem 1 & 2 Dataset
    int dataset[size] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    Node<int>* head = new Node<int>(dataset[0]);
    Node<int>* tail = head;
    for (int i = 1; i < size; i++) {
        tail->next = new Node<int>(dataset[i]);
        tail = tail->next;
    }
    
    
    std::cout << "\n----------PROBLEM 1 & 2----------\n\n";

    std::cout << "Linear Search for '18' in Array:\n";
    linearSearchArr(dataset, size, 18);

    std::cout << "Linear Search for '18' in Linked List:\n";
    linearSearchLL(head, 18);

    std::cout << "\nModified Linear Search for counting '18's in Array:\n";
    linearSearchArrMOD(dataset, size, 18);

    std::cout << "Modified Linear Search for counting '18's in Linked List:\n";
    linearSearchLLMOD(head, 18);

    // Problem 3 & 4 Dataset
    int dataset2[size] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    Node<int>* head2 = new Node<int>(dataset2[0]);
    Node<int>* tail2 = head2;
    for (int i = 1; i < size; i++) {
        tail2->next = new Node<int>(dataset2[i]);
        tail2 = tail2->next;
    }

    std::cout << "\n----------PROBLEM 3 & 4----------\n\n";
    std::cout << "Binary Search for '8' in Array:\n";
    binarySearchArr(dataset2, size, 8);

    std::cout << "Binary Search for '8' in Linked List:\n";
    binarySearchLL(head2, 8);

    std::cout << "\nModified Binary Search for counting '8's in Array:\n";
    binarySearchArrMOD(dataset2, size, 8, 0, size - 1);

    return 0;
}