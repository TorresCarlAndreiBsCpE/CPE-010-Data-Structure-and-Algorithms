#include <iostream>
#include "sortingAlgoSuppl.h"
#include <cstdlib>
#include <time.h>
#include <map>
#include <vector>
#include <string>

// max size = 100 values in the array will be from 1 to 5 only
const int max_size = 100;

int main(){
    int dataset[max_size];
    
    // List of candidates in array
    std::vector<std::string> candidates = {
        "Bo Dalton Capistrano",     // Candidate 1
        "Cornelius Raymon Agustín", // Candidate 2
        "Deja Jayla Bañaga",        // Candidate 3
        "Lalla Brielle Yabut",      // Candidate 4
        "Franklin Relano Castro"    // Candidate 5
    };
    
    // Seed the random number generator with the current time
    srand(time(0));

    // Fill array A[0...100] with values 1 to 5 only
    for (int i = 0; i < max_size; i++) {
        dataset[i] = (rand() % 5) + 1;
    }
    
    // Display the unsorted array of votes
    std::cout << "Unsorted Array of Votes:\n";
    displayArray(dataset, max_size);
    
    // Sort the dataset using insertion sort
    std::cout << "\nInsertion-Sorted Array of Votes:\n";
    insertionSort(dataset, max_size);
    displayArray(dataset, max_size);
    
    // Count votes for each candidate using linear search
    std::map<int, int> voteCount;
    // Outputs individual candidate vote counts
    std::cout << "\n--- Individual Candidate Vote Counts (Linear Search) ---\n";
    for (int id = 1; id <= static_cast<int>(candidates.size()); id++) {
        voteCount[id] = linearSearchArrVoteCount(dataset, max_size, id, candidates);
    }
    
    // Display the winner or tied candidates
    displayVoteWinner(dataset, max_size, candidates);

    return 0;
}