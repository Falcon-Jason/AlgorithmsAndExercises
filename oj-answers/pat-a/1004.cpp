#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

list<int> tree[100]{};
queue<pair<int, int>> bfs_queue{};

bool isleaf(int node) { return tree[node].empty(); }

unordered_map<int, int> bfs() {
    unordered_map<int, int> ans{};
    bfs_queue.push(make_pair(1, 0));
    while (!bfs_queue.empty()) {
        int node = bfs_queue.front().first;
        int depth = bfs_queue.front().second;
        bfs_queue.pop();
        for (auto i = tree[node].begin(); i != tree[node].end(); ++i) {
            bfs_queue.push(make_pair(*i, depth + 1));
        }
        if (isleaf(node)) {
            ans[depth]++;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int parent, son, k;
        cin >> parent >> k;
        for (int i = 0; i < k; i++) {
            cin >> son;
            tree[parent].push_back(son);
        }
    }
    auto res = bfs();
    cout << res[0];
    for (int i = 1; i < res.size(); i++) {
        cout << " " << res[i];
    }
    cout << endl;
}