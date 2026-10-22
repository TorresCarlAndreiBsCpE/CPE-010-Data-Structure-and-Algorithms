#include <iostream>
#include <random>
#include "sortingAlgo2.h"

const int size = 100;

int main() {
    int dataset[size];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < size; i++) {
        dataset[i] = dis(gen);
    }

    std::cout << "\n----Original array----\n";
    displayArray(dataset, size);


    std::cout << "\n----Sorted array by Shell Sort----\n";
    shellSort(dataset, size);
    displayArray(dataset, size);


    std::cout << "\n----Sorted array by Merge Sort----\n";
    mergeSort(dataset, 0, size - 1);
    displayArray(dataset, size);


    std::cout << "\n----Sorted array by Quick Sort----\n";
    quickSort(dataset, 0, size - 1);
    displayArray(dataset, size);

    return 0;
}
