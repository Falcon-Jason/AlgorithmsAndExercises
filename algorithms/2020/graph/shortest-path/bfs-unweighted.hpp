#include <memory>
#include <queue>

#include "../common/directed-graph.hpp"
#include "../common/path.hpp"

// BFS实现无权最短路径搜索
std::shared_ptr<Path> bfsUnweightedShortestPathLength(const DirectedGraph &graph, Vertex source) {
    int size = graph.size();
    SharedArray<int> length{new int[size]};
    SharedArray<Vertex> previous{new int[size]};

    std::queue<int> q{};
    q.push(source);

    for (int i = 0; i < graph.size(); i++) {
        length[i] = -1;
    }

    length[source] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        auto edges = graph[v];
        for (auto i = edges.begin(); i != edges.end(); ++i) {
            if (length[i->next] == -1) {
                q.push(i->next);
                length[i->next] = length[v] + 1;
                previous[i->next] = v;
            }
        }
    }

    return std::make_shared<Path>(size, source, length, previous);
}
