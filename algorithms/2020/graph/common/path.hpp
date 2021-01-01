#include <iostream>

#include "../common/directed-graph.hpp"

#ifndef PATH_HPP
#define PATH_HPP

struct Path {
    int size;
    Vertex source;
    SharedArray<int> distance;
    SharedArray<Vertex> previous;

    Path(int size, Vertex source) {
        this->size = size;
        this->source = source;
        distance.reset(new int[size]);
        previous.reset(new Vertex[size]);
    }

    Path(int size, Vertex source, SharedArray<int> distance, SharedArray<Vertex> previous) {
        this->size = size;
        this->source = source;
        this->distance = distance;
        this->previous = previous;
    }
};

std::ostream &operator<<(std::ostream &out, const Path &path) {
    out << "distance:";

    for (int i = 0; i < path.size; i++) {
        out << " " << path.distance[i];
    }
    out << std::endl;

    out << "previous:";
    for (int i = 0; i < path.size; i++) {
        out << " " << path.previous[i];
    }
    out << std::endl;

    return out;
}

#endif