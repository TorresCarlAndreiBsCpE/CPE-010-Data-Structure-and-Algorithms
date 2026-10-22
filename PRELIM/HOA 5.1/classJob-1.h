#ifndef CLASSJOB_H
#define CLASSJOB_H

#include <iostream>
#include <string>

template <typename T>
class Job {
private:
    int id;
    std::string userName;
    int numPages;

public:
    Job();
    Job(int jobId, std::string user, int pages);
    
    int getId() const;
    std::string getUserName() const;
    int getNumPages() const;

    void print() const;
};

// Default Constructor
template <typename T>
Job<T>::Job() : id(-1), userName(""), numPages(0) {}

// Parameterized Constructor
// Auto Incremented ID, name of the user request to print the job, and the count of pages in the document
template <typename T>
Job<T>::Job(int jobId, std::string user, int pages)
    : id(jobId), userName(user), numPages(pages) {}

// Member Functions

//Retrieves the job's unique identifier.
//Integer represents the Job ID
template <typename T>
int Job<T>::getId() const {
    return id;
}

//Retrieves the username associated with the job
// std::string containing the username
template <typename T>
std::string Job<T>::getUserName() const {
    return userName;
}

//Retrieves the total number of pages in the job
//Integer for page count
template <typename T>
int Job<T>::getNumPages() const {
    return numPages;
}

// Outputs the Printed Prompt of the details of the job to standard output .
// Format: " [Job #<id>] User: <userName> | Pages: <numPages>"
template <typename T>
void Job<T>::print() const {
    std::cout << " [Job #" << id << "] User: " << userName << " | Pages: " << numPages << std::endl;
}

#endif