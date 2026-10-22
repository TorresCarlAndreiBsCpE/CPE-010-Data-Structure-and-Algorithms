#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sortingAlgo.h"

const int max_size = 100;

void displayArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int dataset[max_size];
     
    srand(time(0));

    for(int i = 0; i < max_size; i++) {
        dataset[i] = rand() % 100;
    }
    
    std::cout << "Original Array:\n";
    displayArray(dataset, max_size);

    std::cout << "\nBubble-Sorted Array:\n";
    bubbleSort(dataset, max_size);
    displayArray(dataset, max_size);

    std::cout << "\nInsertion-Sorted Array:\n";
    insertionSort(dataset, max_size);
    displayArray(dataset, max_size);

    std::cout << "\nSelection-Sorted Array:\n";
    selectionSort(dataset, max_size);
    displayArray(dataset, max_size);
    
    return 0;
}