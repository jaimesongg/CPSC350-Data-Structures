#ifndef WGRAPH_H
#define WGRAPH_H

#include <vector>
#include <limits>
#include <iostream>
#include <iomanip>
#include <algorithm>

struct Edge {
    unsigned int src, dest;
    double weight;

    // sorting edges by weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class WGraph {
public:
    WGraph(unsigned int size);
    void addEdge(unsigned int src, unsigned int dest, double weight);
    void computeMST();

private:
    unsigned int m_size;                      // num of vertices
    std::vector<std::vector<double>> m_adj;  // adjacency matrix
    std::vector<std::vector<double>> m_conn; // MST adjacency matrix
};

#endif







