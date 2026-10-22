#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <string>
#include "classJob.h"

//Circular Array Queue
class Printer {
private:
    static const int CAPACITY = 100;  // max pending jobs the Printer can hold
    Job<int> jobs[CAPACITY];          
    int frontIdx;   // index of the job that will be served next
    int rearIdx;    // index where the next job will be inserted
    int count;      // number of jobs currently queued
    int nextJobId;  // auto-incrementing job id generator

public:
    // Prototypes
    // Constructor specifying max capacity of spooler queue
    Printer(size_t capacity = 100);

    // Queue status checks
    bool isEmpty() const;
    bool isFull() const;
    int pendingCount() const;

    // Queue Operations
    void addJob(const std::string& userName, int numPages);
    void processNextJob();
    void processAllJobs();

    // Utility
    void showQueue() const;
};

// Method Definitions *Inline Operations for the compiler to copy-paste the function’s class body directly into the place where it was called*

inline Printer::Printer(size_t capacity) : frontIdx(0), rearIdx(0), count(0), nextJobId(1) {}

//Checks if the Queue is empty
inline bool Printer::isEmpty() const { 
    return count == 0; 
}

//Checks if the Queue is full
inline bool Printer::isFull() const { 
    return count == CAPACITY; 
}

//Checks the current pending job count
inline int Printer::pendingCount() const { 
    return count; 
}

//Enqueue a Job
inline void Printer::addJob(const std::string& userName, int numPages) {
    //Check if the Queue is Full
    if (isFull()) {
        std::cout << "  [Printer] Queue is full! Cannot accept job from "
                  << userName << "." << std::endl;
        return;
    }
    
    // Instantiation of the job with a unique ID and inserts  it at the rear position
    Job<int> newJob(nextJobId++, userName, numPages);
    jobs[rearIdx] = newJob;
    // Advance rear index using Circular Modulo Operation
    rearIdx = (rearIdx + 1) % CAPACITY;
    count++;
    
    //Printer Prompt
    std::cout << "  [Printer] Job #" << newJob.getId() << " from "
              << userName << " (" << numPages << " pages) added to queue. "
              << "Pending jobs: " << count << std::endl;
}

//Dequeue a Job
inline void Printer::processNextJob() {
    // Checks if the queue is empty
    if (isEmpty()) {
        std::cout << "  [Printer] No jobs to process. Printer is idle." << std::endl;
        return;
    }
    
    //Retrieves the job located at the front of the queue
    Job<int> current = jobs[frontIdx];
    //Advance front index using the circular modulo and update the job count
    frontIdx = (frontIdx + 1) % CAPACITY;
    count--; //decrement the count
    
    //Printer Prompt
    std::cout << "  [Printer] Now printing Job #" << current.getId()
              << " for " << current.getUserName() << " ("
              << current.getNumPages() << " pages)... Done." << std::endl;
}

// Processes every pending jobs in the queue sequentially until the queue is empty
inline void Printer::processAllJobs() {
    std::cout << "\n-- Printer processing all pending jobs (FIFO) --" << std::endl;
    if (isEmpty()) {
        std::cout << "  [Printer] Nothing to print." << std::endl;
        return;
    }
    
    //Continuously dequeue jobs until count reaches to zero
    while (!isEmpty()) {
        processNextJob();
    }
    std::cout << "-- All jobs processed. Printer is idle. --\n" << std::endl;
}

//Display all queued jobs from front to back queue format
inline void Printer::showQueue() const {
    std::cout << "  Current queue for the job (" << count << " job(s)), front -> back:" << std::endl;
    if (isEmpty()) {
        std::cout << "    (empty)" << std::endl;
        return;
    }

    // Traverse starting from the front index for 'count' iterations using the modulo operator
    int idx = frontIdx;
    for (int i = 0; i < count; i++) {
        jobs[idx].print();
        idx = (idx + 1) % CAPACITY;
    }
}

#endif