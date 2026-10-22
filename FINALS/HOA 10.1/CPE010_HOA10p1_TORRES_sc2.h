#ifndef CPE010_HOA10P1_TORRES_SC2_H
#define CPE010_HOA10P1_TORRES_SC2_H

#include <iostream>

// stores adjacency list items
struct adjNode {
    int val, cost;
    adjNode* next;
};

// structure to store edges
struct graphEdge {
    int start_ver, end_ver, weight;
};

class DiaGraph {
    // insert new nodes into adjacency list from given graph
    adjNode* getAdjListNode(int value, int weight, adjNode* head) {
        adjNode* newNode = new adjNode;
        newNode->val = value;
        newNode->cost = weight;
        newNode->next = head; // point new node to current head
        return newNode;
    }

    int N; // number of nodes in the graph

public:
    adjNode **head; // adjacency list as array of pointers

    // Constructor
    DiaGraph(graphEdge edges[], int n, int N) {
        this->N = N;
        // allocate array of pointers and initialize to nullptr
        head = new adjNode*[N]();
        
        // construct directed graph by adding edges to it
        for (int i = 0; i < n; i++) {
            int start_ver = edges[i].start_ver;
            int end_ver = edges[i].end_ver;
            int weight = edges[i].weight;
            
            // insert in the beginning
            adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);
            
            // point head pointer to new node
            head[start_ver] = newNode;
        }
    }

    // Destructor - Fixed to properly clear linked lists
    ~DiaGraph() {
        for (int i = 0; i < N; i++) {
            adjNode* curr = head[i];
            while (curr != nullptr) {
                adjNode* nextNode = curr->next;
                delete curr; // Delete individual node
                curr = nextNode;
            }
        }
        delete[] head; // Delete the array of pointers
    }
};

// print all adjacent vertices of given vertex
void display_AdjList(adjNode* ptr, int i) {
    while (ptr != nullptr) {
        std::cout << "(" << i << ", " << ptr->val << ", " << ptr->cost << ") ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

#endif // CPE010_HOA10P1_TORRES_SC2_H