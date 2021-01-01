#include "kruskal-mst.hpp"
#include "prim-mst.hpp"

using namespace std;

int main() {
    int nvertex;
    cin >> nvertex;
    DirectedGraph graph{nvertex};
    DirectedGraph::readFromTable(graph, cin);
    auto resultKruskal = mstKruskal(graph);
    cout << *resultKruskal << endl;

    auto resultPrim = mstPrim(graph, 0);
    cout << *resultPrim;
}