#include "common/directed-graph.hpp"

using namespace std;

static void ReadEdges(DirectedGraph &graph, int nedge, istream &in);

// 有向无环图DP算法实现
int DagShortestPath(DirectedGraph &graph) {
    int nvertex = graph.size();
    int *path_weight = new int[nvertex]{0};
    for (int i = 1; i < nvertex; i++) {
        auto j = graph[i].begin();
        path_weight[i] = path_weight[j->next] + j->weight;
        for (++j; j != graph[i].end(); ++j) {
            int weight = path_weight[j->next] + j->weight;
            path_weight[i] = min(path_weight[i], weight);
        }
    }

    int ans = path_weight[nvertex - 1];
    delete[] path_weight;
    return ans;
}

int main() {
    int nvertex, nedge;
    cin >> nvertex >> nedge;

    DirectedGraph graph{nvertex};
    ReadEdges(graph, nedge, cin);
    cout << DagShortestPath(graph) << endl;

    return 0;
}

static void ReadEdges(DirectedGraph &graph, int nedge, istream &in) {
    for (int i = 0; i < nedge; i++) {
        int p, q, w;
        in >> p >> q >> w;
        graph.connect(q, p, w);
    }
}
