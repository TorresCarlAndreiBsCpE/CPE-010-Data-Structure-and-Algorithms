#include <iostream>
#include <thread>
#include <iomanip>
#include <mutex>
#include <chrono>
#include "sortingAlgo.h"

// Setting up the output stream synchronization
std::mutex coutMutex;

// Static Dataset Generator
namespace Datasets {
    constexpr int SIZE_100 = 100;
    struct Data100 {
        int bestCase[100];   // Sorted order (Best Case)
        int worstCase[100];  // Reversed order (Worst Case)
        int randomCase[100]; // Random order (Average Case)

        constexpr Data100() : bestCase{}, worstCase{}, randomCase{} {
            for (int i = 0; i < 100; ++i) {
                bestCase[i] = i;
                worstCase[i] = 100 - i;
                randomCase[i] = (i * 37 + 13) % 100;
            }
        }
    };
    static const Data100 dataset100;

    constexpr int SIZE_1000 = 1000;
    struct Data1000 {
        int bestCase[1000];
        int worstCase[1000];
        int randomCase[1000];

        constexpr Data1000() : bestCase{}, worstCase{}, randomCase{} {
            for (int i = 0; i < 1000; ++i) {
                bestCase[i] = i;
                worstCase[i] = 1000 - i;
                randomCase[i] = (i * 653 + 101) % 1000;
            }
        }
    };
    static const Data1000 dataset1000;

    constexpr int SIZE_10000 = 10000;
    struct Data10000 {
        int bestCase[10000];
        int worstCase[10000];
        int randomCase[10000];

        constexpr Data10000() : bestCase{}, worstCase{}, randomCase{} {
            for (int i = 0; i < 10000; ++i) {
                bestCase[i] = i;
                worstCase[i] = 10000 - i;
                randomCase[i] = (i * 4925 + 231) % 10000;
            }
        }
    };
    static const Data10000 dataset10000;
}

// Timing memory function (in ms)
template <typename Func, size_t N>
double measureTime(Func sortFunc, const int (&staticArr)[N]) {
    int tempArr[N];
    for (size_t i = 0; i < N; ++i) {
        tempArr[i] = staticArr[i];
    }

    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(tempArr, static_cast<int>(N));
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

// Benchmark Function (Experimental Analysis)
template <size_t N>
void runThreadedBenchmark(int sizeLabel, const int (&best)[N], const int (&worst)[N], const int (&random)[N]) {
    double insertBest = 0.0, insertWorst = 0.0, insertRandom = 0.0;
    
    // Threads for Insertion Sort cases
    std::thread t1([&]() { insertBest = measureTime(insertionSort<int>, best); });
    std::thread t2([&]() { insertWorst = measureTime(insertionSort<int>, worst); });
    std::thread t3([&]() { insertRandom = measureTime(insertionSort<int>, random); });

    t1.join();
    t2.join();
    t3.join();

    // Formatting of the output
    std::lock_guard<std::mutex> lock(coutMutex);

    std::cout << "\n=========================================================\n";
    std::cout << "          THREADED BENCHMARK (N = " << sizeLabel << ")\n";
    std::cout << "=========================================================\n";
    std::cout << std::left << std::setw(18) << "Algorithm"
              << std::setw(18) << "Best Case (ms)"
              << std::setw(18) << "Worst Case (ms)"
              << std::setw(18) << "Random Case (ms)" << "\n";

    std::cout << std::left << std::setw(18) << "Insertion Sort"
              << std::setw(18) << insertBest
              << std::setw(18) << insertWorst
              << std::setw(18) << insertRandom << "\n";
}

// Main Driver
int main() {
    std::cout << std::fixed << std::setprecision(4);

    std::thread worker100([]() {
        runThreadedBenchmark(100, Datasets::dataset100.bestCase, Datasets::dataset100.worstCase, Datasets::dataset100.randomCase);
    });

    std::thread worker1000([]() {
        runThreadedBenchmark(1000, Datasets::dataset1000.bestCase, Datasets::dataset1000.worstCase, Datasets::dataset1000.randomCase);
    });

    std::thread worker10000([]() {
        runThreadedBenchmark(10000, Datasets::dataset10000.bestCase, Datasets::dataset10000.worstCase, Datasets::dataset10000.randomCase);
    });

    worker100.join();
    worker1000.join();
    worker10000.join();

    return 0;
}