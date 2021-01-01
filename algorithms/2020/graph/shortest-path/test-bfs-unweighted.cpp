#include <iostream>

#include "bfs-unweighted.hpp"

using namespace std;

int main() {
    int nvertex;
    cin >> nvertex;
    DirectedGraph graph{nvertex};
    DirectedGraph::readFromTable(graph, cin);

    cout << *bfsUnweightedShortestPathLength(graph, 0);
}