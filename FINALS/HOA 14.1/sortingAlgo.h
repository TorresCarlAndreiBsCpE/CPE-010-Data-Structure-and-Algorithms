#ifndef SORTINGALGO_H
#define SORTINGALGO_H
#include <iostream>
#include <utility>

template <typename T>
void bubbleSort(T arr[], int arrsize){
    for(int i = 0; i < arrsize; i++){
        for(int j = i+1; j < arrsize; j++){
           
            if(arr[j] > arr[i]){
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

template <typename T>
void insertionSort(T arr[], int arrsize){
    int k = 1, j;
    T temp;

    while(k < arrsize){
        temp = arr[k];
        j = k-1;
        while(j >= 0 && temp <= arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        k++;
    }
}
#endif