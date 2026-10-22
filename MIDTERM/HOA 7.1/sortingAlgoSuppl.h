#ifndef SORTINGALGOSUPPL_H
#define SORTINGALGOSUPPL_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

// Function to print array elements
void displayArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) { // Print each element followed by a space
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Insertion Sort algorithm
template <typename T>
void insertionSort(T arr[], int arrsize) {
    int k = 1, j;
    T temp;
    // Sort the array in ascending order using insertion sort
    while (k < arrsize) {
        temp = arr[k];
        j = k - 1;
        while (j >= 0 && temp <= arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        k++;
    }
}

// Linear search function to count votes for a given candidate ID (No comparison counter)
template <typename T>
int linearSearchArrVoteCount(const T dataset[], int arrSize, int candidatesID, const std::vector<std::string>&candidates) {
    int voteCounter = 0;
    // Count votes for the specified candidate ID
    for (int i = 0; i < arrSize; i++) {
        if (dataset[i] == candidatesID) {
            voteCounter++;
        }
    }
    // Output the vote count for the candidate
    std::cout << "Candidate " << candidatesID << " (" << candidates[candidatesID - 1] 
              << ") received " << voteCounter << " votes.\n";
    // Return the total votes counted for the candidate
    return voteCounter;
}

// Function to find and display the winner or tied candidates
template <typename T>
void displayVoteWinner(const T dataset[], int arrSize, const std::vector<std::string>& candidates) {
    // Map to hold candidate IDs and their corresponding vote counts
    std::map<int, int> voteCount;

    // Tally votes from array
    for (int i = 0; i < arrSize; i++) {
        voteCount[dataset[i]]++;
    }
    
    int maxVotes = 0;

    // Find the maximum votes received by any candidate
    for (const auto& pair : voteCount) {
        if (pair.second > maxVotes) {
            maxVotes = pair.second;
        }
    }

    // Collect candidates that achieved maxVotes
    std::vector<int> winners;
    for (const auto& pair : voteCount) {
        if (pair.second == maxVotes && maxVotes > 0) {
            winners.push_back(pair.first);
        }
    }
    
    // Display the election results
    std::cout << "\n-------------ELECTION RESULTS-------------\n";
    if (winners.empty()) { // No votes were counted for any candidate
        std::cout << "No votes were counted for each candidate.\n";

    } else if (winners.size() == 1) { // Single winner
        int winnerID = winners[0];
        std::cout << "The winner of the election is Candidate " << winnerID 
                  << " (" << candidates[winnerID - 1] << ") with " << maxVotes << " votes!!!\n";

    } else { // Tie situation
        std::cout << "It's a tie! No clear winner in the election.\n";
        std::cout << "The following candidates tied with " << maxVotes << " votes each:\n";
        for (int winnerID : winners) { // Display each tied candidate's ID and name
            std::cout << " - Candidate " << winnerID << " (" << candidates[winnerID - 1] << ")\n";
        }
    }
    std::cout << "\n-----------------------------------\n";
}

#endif