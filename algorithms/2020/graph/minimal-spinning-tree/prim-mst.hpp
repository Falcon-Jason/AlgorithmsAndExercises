#include <set>

#include "../common/directed-graph.hpp"
#include "../common/vertex-queue.hpp"

template <class VertexQueue = BinaryHeapVertexQueue>
std::shared_ptr<DirectedGraph> mstPrim(const DirectedGraph& graph, Vertex source) {
    int size = graph.size();
    SharedArray<int> key{new int[size]};
    SharedArray<int> prev{new int[size]};

    for (int i = 0; i < size; i++) {
        key[i] = __INT_MAX__;
        prev[i] = -1;
    }
    key[source] = 0;

    VertexQueue queue{size, key};
    queue.resetWeight(source, 0);

    std::set<Vertex> traversed{};

    while (!queue.empty()) {
        Vertex u = queue.extractMin();
        traversed.insert(u);
        for (auto i = graph[u].begin(); i != graph[u].end(); ++i) {
            if (!traversed.count(i->next) && i->weight < key[i->next]) {
                prev[i->next] = u;
                queue.resetWeight(i->next, i->weight);
            }
        }
    }

    std::shared_ptr<DirectedGraph> result{new DirectedGraph{size}};
    for (int i = 0; i < size; i++) {
        if (i != source) {
            result->connect(prev[i], i, key[i]);
        }
    }

    return result;
}