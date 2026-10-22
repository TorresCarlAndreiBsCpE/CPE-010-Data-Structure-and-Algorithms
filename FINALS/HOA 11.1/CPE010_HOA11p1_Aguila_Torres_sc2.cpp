#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>

bool unique(const std::vector<int>& A, long long& comparisons) {
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = i + 1; j < A.size(); ++j) {
            comparisons++; // Increment the comparisons for each comparison made
            if (A[i] == A[j]) {
                return false; // Found a duplicate
            }
        }
    }
    return true;
}

std::vector<int> makeWorstCase(int n) {
    // Create a vector with n unique elements in ascending order
    std::vector<int> worst_case(n);
    // Fill the vector with unique values from 0 to n-1
    for (int i = 0; i < n; ++i) {
        // Assign unique values to the vector
        worst_case[i] = i;
    }
    // Return the vector representing the worst-case scenario for the unique function
    return worst_case;
}

// Measure the timing of the unique function for different sizes of input
auto start = std::chrono::high_resolution_clock::now();
auto end = std::chrono::high_resolution_clock::now();
double ms = std::chrono::duration<double, std::milli>(end - start).count();

// Main function to run the tests
int main() {
    // Define the sizes of input to test
    std::vector<int> sizes = {100, 1000, 10000, 20000};
    
    // Format the output table header
    std::cout << std::setw(8)  << "n"
              << std::setw(16) << "comparisons"
              << std::setw(16) << "n(n-1)/2"
              << std::setw(14) << "time(ms)"
              << std::setw(10) << "unique?" << "\n";
    
    // Loop through each size and test the unique function
    for (size_t i = 0; i < sizes.size(); ++i) {
        int n = sizes[i];
        std::vector<int> worst_case = makeWorstCase(n);
        // Initialize the comparison counter
        long long comparisons = 0;
    // Measure the time taken to check for uniqueness
        start = std::chrono::high_resolution_clock::now();
        bool is_unique = unique(worst_case, comparisons);
        end = std::chrono::high_resolution_clock::now();
        ms = std::chrono::duration<double, std::milli>(end - start).count();
        long long expected = (long long)n * (n - 1) / 2;
    
        // Output the results in the formatted table
        std::cout << std::setw(8)  << n
                  << std::setw(16) << comparisons
                  << std::setw(16) << expected
                  << std::setw(14) << std::fixed << std::setprecision(4) << ms
                  << std::setw(10) << is_unique << "\n";
    }
    return 0;
}