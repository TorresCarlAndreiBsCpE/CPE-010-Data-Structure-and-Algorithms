#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
#include "searchingAlgo.h"

//timer function to measure search time in milliseconds
template <typename Func>
double getTime(Func searchFunc) {
    auto start = std::chrono::high_resolution_clock::now();
    searchFunc();
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}

int main() {
    // Array sizes required by the assignment
    int sizes[] = {1000, 10000, 100000};
    // Format the output header
    std::cout << "\n=================================================================================\n";
    std::cout << std::left << std::setw(15) << "Input Size (N)"
              << std::setw(35) << "Binary Search (Worst-Case)"
              << std::setw(35) << "Linear Search (Worst-Case)" << "\n";
    std::cout << "=================================================================================\n";

    for (int size : sizes) {
        // Create a sorted array: [0, 1, 2, ..., size - 1]
        std::vector<int> dataset(size);
        for (int i = 0; i < size; ++i) {
            dataset[i] = i;
        }

        // Searching for -1 which forces the worst-case (scans entire array / max splits)
        int target = -1;

        // Turn off cout temporarily so "The element is not found" won't print during timer
        std::streambuf* origCout = std::cout.rdbuf(nullptr);

        double binaryTime = getTime([&]() {
            binarySearchArr(dataset.data(), size, target);
        });

        double linearTime = getTime([&]() {
            linearSearchArr(dataset.data(), size, target);
        });

        // Turn cout back on
        std::cout.rdbuf(origCout);

        // Display results in milliseconds
        std::cout << std::left << std::setw(15) << size
                  << std::setw(35) << (std::to_string(binaryTime) + " ms")
                  << std::setw(35) << (std::to_string(linearTime) + " ms") << "\n";
    }

    std::cout << "=================================================================================\n";

    return 0;
}