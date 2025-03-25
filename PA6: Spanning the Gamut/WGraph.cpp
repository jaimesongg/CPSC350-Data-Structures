#include "WGraph.h"
#include <numeric>

WGraph::WGraph(unsigned int size) 
    : m_size(size), 
      m_adj(size, std::vector<double>(size, std::numeric_limits<double>::max())), 
      m_conn(size, std::vector<double>(size, 0.0)) {
    // initialize diagonal of adjacency matrix to 0
    for (unsigned int i = 0; i < size; ++i) {
        m_adj[i][i] = 0.0;
    }
}

void WGraph::addEdge(unsigned int src, unsigned int dest, double weight) {
    if (src < m_size && dest < m_size) {
        m_adj[src][dest] = weight;
        m_adj[dest][src] = weight; // since graph is undirected
    }
}

void WGraph::computeMST() {
    // prepare list of all edges
    std::vector<Edge> edges;
    for (unsigned int i = 0; i < m_size; ++i) {
        for (unsigned int j = i + 1; j < m_size; ++j) {
            if (m_adj[i][j] < std::numeric_limits<double>::max()) {
                edges.push_back({i, j, m_adj[i][j]});
            }
        }
    }

    // sort edges by weight
    std::sort(edges.begin(), edges.end());

    // initialize union-find structure
    std::vector<unsigned int> parent(m_size);
    std::iota(parent.begin(), parent.end(), 0);

    auto find = [&parent](unsigned int v) {
        while (v != parent[v]) {
            parent[v] = parent[parent[v]]; // path compression
            v = parent[v];
        }
        return v;
    };

    auto unionSets = [&parent, &find](unsigned int u, unsigned int v) {
        parent[find(u)] = find(v);
    };

    // compute MST using Kruskals algorithm
    double mstCost = 0.0;
    std::vector<Edge> mstEdges;

    for (const auto& edge : edges) {
        if (find(edge.src) != find(edge.dest)) {
            unionSets(edge.src, edge.dest);
            mstCost += edge.weight;
            mstEdges.push_back(edge);
        }
    }

    std::cout << "The MST Cost is: " << mstCost << "\n";

    // initialize MST adjacency matrix
    for (unsigned int i = 0; i < m_size; ++i) {
        for (unsigned int j = 0; j < m_size; ++j) {
            m_conn[i][j] = 0.0; // Start with no edges
        }
    }

    // populate MST adjacency matrix
    for (const auto& edge : mstEdges) {
        m_conn[edge.src][edge.dest] = edge.weight;
        m_conn[edge.dest][edge.src] = edge.weight;
    }

    // print MST adjacency matrix
    for (unsigned int i = 0; i < m_size; ++i) {
        for (unsigned int j = 0; j < m_size; ++j) {
            std::cout << std::fixed << std::setprecision(1) << m_conn[i][j] << " ";
        }
        std::cout << "\n";
    }
}

