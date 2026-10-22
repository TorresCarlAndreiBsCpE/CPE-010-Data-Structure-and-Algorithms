#ifndef SORTINGALGO2_H
#define SORTINGALGO2_H
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

/* MERGE SORT
Declare an array Arr of length N
If N=1, Arr is already sorted
If N>1,
Left = 0, right = N-1
Find middle = (left + right)/2
Call merge_sort(Arr,left,middle) =>sort first half recursively
Call merge_sort(Arr,middle+1,right) => sort second half recursively
Call merge(Arr, left, middle, right) to merge sorted arrays in above steps.
Exit
*/
template <typename T>
void merge(T arr[], int left, int middle, int right) {
    T temp[right - left + 1];

    int i = left;
    int j = middle + 1;
    int temp_pos = 0;

    while (i <= middle && j <= right) {
        if (arr[i] < arr[j]) {
            temp[temp_pos] = arr[i];
            i++;
            temp_pos++;
        } else {
            temp[temp_pos] = arr[j];
            j++;
            temp_pos++;
        }
    }
    while (i <= middle) {
        temp[temp_pos] = arr[i];
        i++;
        temp_pos++;
    }
    while (j <= right) {
        temp[temp_pos] = arr[j];
        j++;
        temp_pos++;
    }
    int k = 0;
    for (int i = left; i <= right; i++) {
        arr[i] = temp[k];
        k++;
    }
}

template <typename T>
void mergeSort(T arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = (left + right) / 2;

    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

 /* QUICKSORT
quicksort(A, low, high)
    Declare array A[N] to be sorted
    low = 1st element; high = last element; pivot
    if(low < high)
    begin
    pivot = partition (A,low,high);
    quicksort(A,low,pivot-1)
    quicksort(A,pivot+1,high)
End
    */
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

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
#endif // SORTINGALGOPRT2_H