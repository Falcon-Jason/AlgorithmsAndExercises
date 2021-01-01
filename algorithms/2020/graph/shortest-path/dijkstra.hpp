#include <memory>

#include "../common/directed-graph.hpp"
#include "../common/path.hpp"
#include "../common/vertex-queue.hpp"

#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

template <class VertexQueue>
std::shared_ptr<Path> dijkstraShortestPath(const DirectedGraph &graph, Vertex source) {
    int size = graph.size();
    std::shared_ptr<Path> path{new Path{size, source}};
    VertexQueue queue{size, path->distance};  // 未遍历顶点集合

    auto initSingleSource = [&size, &path, &source]() {
        for (int i = 0; i < size; i++) {
            path->distance[i] = __INT_MAX__;
            path->previous[i] = -1;
        }
        path->distance[source] = 0;
    };

    auto relax = [&path, &queue](Vertex p, Vertex q, int weight) {
        if (path->distance[q] < 0 || path->distance[q] > path->distance[p] + weight) {
            queue.resetWeight(q, path->distance[p] + weight);
            path->previous[q] = p;
        }
    };

    initSingleSource();

    while (!queue.empty()) {
        Vertex v = queue.extractMin();
        auto &edges = graph[v];
        for (auto i = edges.begin(); i != edges.end(); ++i) {
            relax(v, i->next, i->weight);
        }
    }

    return path;
}

#endif