#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

void merge(std::vector<int> &a, int l, int m, int r) {
    std::vector<int> tmp(r - l + 1);
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) tmp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i <= m) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    std::copy(tmp.begin(), tmp.end(), a.begin() + l);
}

void mergeSort(std::vector<int> &a, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

void mergeSortThreaded(std::vector<int> &a, int l, int r, int depth) {
    if (l >= r) return;
    if (depth <= 0) { mergeSort(a, l, r); return; }
    int m = (l + r) / 2;
    std::thread left(mergeSortThreaded, std::ref(a), l, m, depth - 1);
    mergeSortThreaded(a, m + 1, r, depth - 1);
    left.join();
    merge(a, l, m, r);
}

int main() {
    const int N = 2000000;
    std::mt19937 rng(42);
    std::vector<int> base(N);
    for (auto &x : base) x = rng() % 1000000;

    std::vector<int> a = base;
    auto t0 = std::chrono::high_resolution_clock::now();
    mergeSort(a, 0, N - 1);
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Single-thread: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()
              << " ms, sorted=" << std::is_sorted(a.begin(), a.end()) << std::endl;

    for (int d : {1, 2, 3}) {
        std::vector<int> b = base;
        auto s = std::chrono::high_resolution_clock::now();
        mergeSortThreaded(b, 0, N - 1, d);
        auto e = std::chrono::high_resolution_clock::now();
        std::cout << "Threaded depth " << d << " (" << (1 << d) << " threads): "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(e - s).count()
                  << " ms, sorted=" << std::is_sorted(b.begin(), b.end()) << std::endl;
    }
    return 0;
}