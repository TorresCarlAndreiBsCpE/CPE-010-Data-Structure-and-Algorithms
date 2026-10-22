#include <iostream>
#include "CPE010_HOA10p1_TORRES_sc2.h"

int main()
{
    // graph edges array.
    graphEdge edges[] = {
        // (x, y, w) -> edge from x to y with weight w
        {0, 1, 2}, {0, 2, 4}, {1, 4, 3}, {2, 3, 2}, {3, 1, 4}, {4, 3, 3}
    };
    
    int N = 6; // Number of vertices in the graph
    
    // calculate number of edges
    int n = sizeof(edges) / sizeof(edges[0]);
    
    // construct graph
    DiaGraph diagraph(edges, n, N);
    
    // print adjacency list representation of graph
    std::cout << "Graph adjacency list \n(start_vertex, end_vertex, weight):" << std::endl;
    
    // Fixed: Cleaned up scope braces and enclosed the loop properly
    for (int i = 0; i < N; i++) {
        // display adjacent vertices of vertex i
        display_AdjList(diagraph.head[i], i);
    }
    
    return 0;
}
