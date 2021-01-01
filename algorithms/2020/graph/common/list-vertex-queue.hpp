#include <functional>

#include "directed-graph.hpp"
#ifndef LIST_VERTEX_QUEUE
#define LIST_VERTEX_QUEUE

class ListVertexQueue {
private:
    int size;
    SharedArray<int> weight;
    std::list<Vertex> vertexes;

public:
    ListVertexQueue(int size, SharedArray<int> weight);

    void resetWeight(Vertex v, int w) { weight[v] = w; }

    Vertex extractMin();

    bool empty() const { return vertexes.empty(); }
};

#endif

ListVertexQueue::ListVertexQueue(int size, SharedArray<int> weight) {
    this->size = size;
    this->weight = weight;
    vertexes.clear();

    for (int i = 0; i < size; i++) {
        vertexes.push_back(i);
    }
}

Vertex ListVertexQueue::extractMin() {
    auto min = vertexes.begin();
    for (auto i = vertexes.begin(); i != vertexes.end(); ++i) {
        if (weight[*i] < weight[*min]) {
            min = i;
        }
    }
    int minval = *min;
    vertexes.erase(min);

    return minval;
}