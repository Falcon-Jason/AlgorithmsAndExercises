/**
 * @file: directed-graph.hpp
 * @brief: 有向图ADT及其实现
 */

#include <boost/shared_array.hpp>
#include <iostream>
#include <list>
#include <memory>
#include <vector>

#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#ifdef USE_LETTERS_AS_VERTEX_NAME
#define OUT(x) (char)((x) + 'A')
#else
#define OUT(x) (x)
#endif

template <class T>
using SharedArray = boost::shared_array<T>;

using Vertex = int;

class DirectedGraph {
public:
    struct Edge {
        Vertex next;
        int weight;
    };

    struct EdgeWithOrigin;

private:
    SharedArray<std::list<Edge>> data;
    int nvertex;

public:
    DirectedGraph(int size) {
        nvertex = size;
        data.reset(new std::list<Edge>[size]);
    }

    const std::list<Edge> &operator[](Vertex v) const { return data[v]; }

    std::shared_ptr<std::vector<EdgeWithOrigin>> allEdges() const;

    int size() const { return nvertex; }

    void connect(int p, int q, int w = 1) { data[p].push_back(Edge{q, w}); }

    friend std::ostream &operator<<(std::ostream &out, const DirectedGraph &graph);

    static void readFromMatrix(DirectedGraph &graph, std::istream &in = std::cin);

    static void readFromTable(DirectedGraph &graph, std::istream &in = std::cin);
};

std::ostream &operator<<(std::ostream &out, const DirectedGraph &graph) {
    for (int i = 0; i < graph.nvertex; i++) {
        out << i;
        for (auto j = graph[i].begin(); j != graph[i].end(); ++j) {
            out << " (" << j->next << "," << i << ":" << j->weight << ")";
        }
        out << std::endl;
    }
    return out;
}

// 输入图（使用权矩阵）
void DirectedGraph::readFromMatrix(DirectedGraph &graph, std::istream &in) {
    int size = graph.size();
    int weight;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            in >> weight;
            if (weight != 0) {
                graph.connect(i, j, weight);
            }
        }
    }
}

// 输入图（使用 (p,q,w) 三元组）
void DirectedGraph::readFromTable(DirectedGraph &graph, std::istream &in) {
    int nedge;
    in >> nedge;
    for (int i = 0; i < nedge; i++) {
        int p, q, w;
        in >> p >> q >> w;
        graph.connect(p, q, w);
    }
}

struct DirectedGraph::EdgeWithOrigin {
    Vertex origin;
    Vertex target;
    int weight;

    EdgeWithOrigin(Vertex p, Vertex q, int w) : origin{p}, target{q}, weight{w} {}

    bool operator<(const EdgeWithOrigin &that) const { return weight < that.weight; }
};

std::shared_ptr<std::vector<DirectedGraph::EdgeWithOrigin>> DirectedGraph::allEdges() const {
    using namespace std;
    shared_ptr<vector<EdgeWithOrigin>> edges{new vector<EdgeWithOrigin>{}};
    for (int i = 0; i < nvertex; i++) {
        for (auto j = data[i].begin(); j != data[i].end(); ++j) {
            edges->push_back({i, j->next, j->weight});
        }
    }
    return edges;
}
#endif