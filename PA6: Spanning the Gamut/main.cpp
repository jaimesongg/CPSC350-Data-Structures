#include <iostream>
#include "WGraph.h"

int main() {
    // create graph with the size given in the input file
    WGraph graph(7);

    // add edges 
    graph.addEdge(0, 1, 1.0);
    graph.addEdge(0, 3, 1.0);
    graph.addEdge(0, 4, 8.0);
    graph.addEdge(0, 5, 10.0);
    graph.addEdge(1, 2, 1.0);
    graph.addEdge(1, 5, 10.0);
    graph.addEdge(2, 4, 1.0);
    graph.addEdge(3, 4, 5.0);
    graph.addEdge(3, 5, 5.0);
    graph.addEdge(4, 5, 2.0);
    graph.addEdge(4, 6, 2.0);

    // compute and print MST
    graph.computeMST();

    return 0;
}


