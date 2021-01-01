#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#ifndef BINARY_HEAP_CPP
#define BINARY_HEAP_CPP

template <class T, class Compare = std::less<T>>
class BinaryHeap {
private:
    std::vector<T> content;
    Compare comp;

public:
    BinaryHeap() : content{} {}

    template <class InputIterator>
    BinaryHeap(InputIterator begin, InputIterator end)
        : content{begin, end} { buildHeap(); }

    template <class Container>
    BinaryHeap(const Container& container)
        : content{container.begin(), container.end()} { buildHeap(); }

    bool empty() const {
        return content.empty();
    }

    const T& peek() const {
        assert(!content.empty());
        return content.front();
    }

    T extract() {
        assert(!content.empty());
        T result = content.front();

        content.front() = content.back();
        content.pop_back();
        sink(0);

        return result;
    }

    void insert(const T& item) {
        content.push_back(item);
        swim(content.size() - 1, item);
    }

    void resetValue(int pos, const T& value) {
        assert(pos >= 0);
        T exVal{content[pos]};
        content[pos] = exVal;
        if (comp(value, exVal)) {
            swim(pos);
        } else {
            sink(pos);
        }
    }

private:
    inline int parent(int i) { return (i - 1) / 2; }
    inline int left(int i) { return 2 * i + 1; }
    inline int right(int i) { return 2 * i + 2; }

    void buildHeap() {
        for (int i = content.size() / 2 - 1; i >= 0; --i) {
            sink(i);
        }
    }

    void sink(int i) {
        for (;;) {
            int l = left(i);   // the left index
            int r = right(i);  // the right index
            int ext = i;       // the extremum index
            if (l < content.size() && comp(content[l], content[ext])) {
                ext = l;
            }
            if (r < content.size() && comp(content[r], content[ext])) {
                ext = r;
            }

            if (ext == i) {
                break;
            }
            swap(content[i], content[ext]);
            i = ext;
        }
    }

    void swim(int i) {
        while (i > 0 && comp(content[i], content[parent(i)])) {
            swap(content[i], content[parent(i)]);
            i = parent(i);
        }
    }
};
#endif