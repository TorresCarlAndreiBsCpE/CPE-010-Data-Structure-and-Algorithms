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
constexpr T getMiddleArr(T low, T up) {
    return low + (up - low) / 2;
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