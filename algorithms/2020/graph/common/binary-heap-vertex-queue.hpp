#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>

#include "directed-graph.hpp"
#ifndef BINARY_HEAP_VERTEX_QUEUE_HPP
#define BINARY_HEAP_VERTEX_QUEUE_HPP

class BinaryHeapVertexQueue {
private:
    int size;
    int heapsize;
    std::unique_ptr<int[]> position;
    std::unique_ptr<Vertex[]> heap;
    SharedArray<int> weight;

public:
    BinaryHeapVertexQueue(int size, SharedArray<int> weight);
    void resetWeight(Vertex v, int value);
    int extractMin();
    bool empty() const { return heapsize == 0; }

private:
    inline int parent(int i) { return (i - 1) / 2; }
    inline int left(int i) { return 2 * i + 1; }
    inline int right(int i) { return 2 * i + 2; }

    void swapPosition(int p, int q);
    void insert(int i, int value);
    void sink(int p);
    void swim(int p);
};

BinaryHeapVertexQueue::BinaryHeapVertexQueue(int size, SharedArray<int> weight) {
    this->size = size;
    this->heapsize = 0;
    this->weight = weight;

    position.reset(new int[size]);
    heap.reset(new int[size]);

    for (int i = 0; i < size; i++) {
        insert(i, weight[i]);
    }
}

void BinaryHeapVertexQueue::resetWeight(Vertex v, int weight) {
    assert(v >= 0 && position[v] >= 0);
    int exWeight = this->weight[v];
    this->weight[v] = weight;
    if (weight < exWeight) {
        swim(position[v]);
    } else {
        sink(position[v]);
    }
}

// void BinaryHeapVertexQueue::refresh(Vertex v) {
//     int pos = position[v];
//     if (pos > 0 && weight[heap[pos]] < weight[heap[parent(pos)]]) {
//         swim(v);
//     } else {
//         sink(v);
//     }
// }

int BinaryHeapVertexQueue::extractMin() {
    assert(!empty());
    int result = heap[0];
    position[heap[0]] = -1;
    swapPosition(0, --heapsize);
    sink(0);

    return result;
}

void BinaryHeapVertexQueue::swapPosition(int p, int q) {
    std::swap(heap[p], heap[q]);
    position[heap[p]] = p;
    position[heap[q]] = q;
}

void BinaryHeapVertexQueue::insert(int i, int value) {
    position[i] = heapsize;
    heap[heapsize++] = i;
    weight[i] = value;

    swim(heapsize - 1);
}

void BinaryHeapVertexQueue::sink(int p) {
    int l = left(p);
    int r = right(p);
    int next = p;
    if (l < heapsize && weight[heap[l]] < weight[heap[next]]) {
        next = l;
    }
    if (r < heapsize && weight[heap[r]] < weight[heap[next]]) {
        next = r;
    }
    if (next != p) {
        swapPosition(p, next);
        swim(next);
    }
}

void BinaryHeapVertexQueue::swim(int p) {
    while (p > 0 && weight[heap[p]] < weight[heap[parent(p)]]) {
        swapPosition(p, parent(p));
    }
}

#endif