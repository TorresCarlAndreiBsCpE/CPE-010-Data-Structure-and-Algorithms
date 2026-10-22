#ifndef SORTINGALGO2SUPPLPRB1_H
#define SORTINGALGO2SUPPLPRB1_H
#include <iostream>


template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void shellSort(T arr[], int size) {
    /* SHELL SORT
    shellSort(array, size)
        for intervaal i <= size /2n down to 1
            for each interval *i* in array
                sort all the elements at interrval *i*
    end shellSort
    */
    for (int gap = size / 2 ; gap >= 1; gap = gap / 2) {
        for (int i = gap; i < size; i++) {
            T temp = arr[i];
            int pos = i;
            while (pos >= gap && arr[pos - gap] > temp) {
                arr[pos] = arr[pos - gap];
                pos = pos - gap;
            }
            arr[pos] = temp;
        }
    }
}

template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high]; // pivot
    int i = (low - 1);   // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template <typename T>
void quickSort(T arr[], int low, int high) {

    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Sort elements before partition using shellSort
        shellSort(arr + low, pi - low);

        // Sort elements after partition using shellSort
        shellSort(arr + pi + 1, high - pi);
    }
}
#endif // SORTINGALGO2SUPPL_H