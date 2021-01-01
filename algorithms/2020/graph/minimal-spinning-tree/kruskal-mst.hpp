#include <algorithm>
#include <memory>

#include "../common/directed-graph.hpp"
#include "../common/union-find-set.hpp"

#ifndef KRUSKAL_MST
#define KRUSKAL_MST
std::shared_ptr<DirectedGraph> mstKruskal(const DirectedGraph& graph) {
    auto size = graph.size();
    UnionFindSet ufset{size};

    std::shared_ptr<DirectedGraph> result{new DirectedGraph{size}};
    auto edges = graph.allEdges();
    sort(edges->begin(), edges->end());

    for (auto i = edges->begin(); i != edges->end(); ++i) {
        if (!ufset.connected(i->origin, i->target)) {
            result->connect(i->origin, i->target, i->weight);
            ufset.connect(i->origin, i->target);
        }
    }

    return result;
}
#endif