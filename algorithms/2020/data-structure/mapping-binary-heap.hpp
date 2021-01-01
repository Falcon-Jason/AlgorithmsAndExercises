#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>

#ifndef MAPPING_BINARY_HEAP_HPP
#define MAPPING_BINARY_HEAP_HPP

template <class Compare = std::less<int>>
class MappingBinaryHeap {
private:
    Compare comp;

    int size;
    int heapsize;
    std::unique_ptr<int[]> position;
    std::unique_ptr<int[]> values;
    std::unique_ptr<int[]> heap;

public:
    MappingBinaryHeap(int size, bool insertAll = false, int defaultValue = 0) : size{size} {
        position.reset(new int[size]);
        values.reset(new int[size]);
        heap.reset(new int[size]);
        if (!insertAll) {
            heapsize = 0;
            for (int i = 0; i < size; i++) {
                position[i] = -1;
            }
            return;
        }
        heapsize = size;
        for (int i = 0; i < size; i++) {
            position[i] = i;
            values[i] = defaultValue;
            heap[i] = i;
        }
    }

    bool empty() const {
        return heapsize == 0;
    }

    int peek() const {
        assert(!empty());
        return heap[0];
    }

    int extract() {
        assert(!empty());

        int result = heap[0];
        position[heap[0]] = -1;
        swapPosition(0, heapsize - 1);
        heapsize--;
        sink(0);

        return result;
    }

    void insert(int i, int value) {
        assert(position[i] < 0 && heapsize <= size);
        position[i] = heapsize;
        heap[heapsize++] = i;
        values[i] = value;

        swim(heapsize - 1);
    }

    void resetValue(int i, int value) {
        assert(position[i] >= 0);
        int exValue = values[i];
        values[i] = value;
        if (comp(value, exValue)) {
            swim(position[i]);
        } else {
            sink(position[i]);
        }
    }

private:
    inline int parent(int i) { return (i - 1) / 2; }
    inline int left(int i) { return 2 * i + 1; }
    inline int right(int i) { return 2 * i + 2; }

    void swapPosition(int p, int q) {
        std::swap(heap[p], heap[q]);
        position[heap[p]] = p;
        position[heap[q]] = q;
    }

    void sink(int p) {
        int l = left(p);
        int r = right(p);
        int next = p;
        if (l < heapsize && comp(values[heap[l]], values[heap[next]])) {
            next = l;
        }
        if (r < heapsize && comp(values[heap[r]], values[heap[next]])) {
            next = r;
        }
        if (next != p) {
            swapPosition(p, next);
            swim(next);
        }
    }

    void swim(int p) {
        while (p > 0 && comp(values[heap[p]], values[heap[parent(p)]])) {
            swapPosition(p, parent(p));
        }
    }
};

#endif