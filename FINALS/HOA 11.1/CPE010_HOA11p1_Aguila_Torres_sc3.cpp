#include <iostream>
#include <chrono>
#include <iomanip> // Needed for std::setw and std::left

// Algorithm 1: Linear Recursive Power O(n)
int rpower(int x, int n) {
    if (n == 0) return 1;
    return x * rpower(x, n - 1);
}

// Algorithm 2: Binary Recursive Power O(log n)
int brpower(int x, int n) {
    if (n == 0) return 1;
    if (n % 2 != 0) {
        int y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else {
        int y = brpower(x, n / 2);
        return y * y;
    }
}

int main() {
    int x = 1; // x = 1 prevents integer overflow during runtime testing
    int exponents[] = {100, 1000, 5000, 10000, 20000};

    // Print headers with fixed column widths
    std::cout << std::left 
              << std::setw(15) << "Exponent (n)" 
              << std::setw(20) << "rpower Time (us)" 
              << std::setw(20) << "brpower Time (us)" << "\n";
    std::cout << "---------------------------------------------------------\n";

    for (int n : exponents) {
        // Measure rpower execution time
        auto start1 = std::chrono::steady_clock::now();
        rpower(x, n);
        auto end1 = std::chrono::steady_clock::now();
        auto t_rpower = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count();

        // Measure brpower execution time
        auto start2 = std::chrono::steady_clock::now();
        brpower(x, n);
        auto end2 = std::chrono::steady_clock::now();
        auto t_brpower = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count();

        // Print formatted row matching fixed widths
        std::cout << std::left 
                  << std::setw(15) << n 
                  << std::setw(20) << t_rpower 
                  << std::setw(20) << t_brpower << "\n";
    }

    return 0;
}