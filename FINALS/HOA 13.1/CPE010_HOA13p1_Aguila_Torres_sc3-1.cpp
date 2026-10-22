#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <chrono>


int globalValue = 0;


void add(int value) {
    
    std::this_thread::sleep_for(std::chrono::milliseconds(value * 10));

    globalValue += value;
}


void display(const std::string &label) {
    std::cout << label << " : globalValue = " << globalValue << std::endl;
}

int main() {
    std::vector<int> values = {10, 20, 30};

    std::vector<std::thread> threads;

    for (int i = 0; i < values.size(); i++) {
        threads.push_back(std::thread(add, values[i]));
    }

    display("Display (before any join)");

    threads[0].join();   
    display("Display (after T1.join)");

    threads[1].join();   
    display("Display (after T2.join)");

    threads[2].join();   
    display("Display (after T3.join)");

    return 0;
}