#include "dijkstra.hpp"
using namespace std;

int main() {
    int nvertex;
    cin >> nvertex;
    DirectedGraph graph{nvertex};
    DirectedGraph::readFromTable(graph, cin);
    cout << *dijkstraShortestPath<BinaryHeapVertexQueue>(graph, 0);
    cout << *dijkstraShortestPath<ListVertexQueue>(graph, 0);
}