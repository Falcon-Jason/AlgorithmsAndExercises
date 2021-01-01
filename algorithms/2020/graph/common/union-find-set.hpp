/**
 * @file: union-find-set.hpp
 * @brief: 并查集ADT及路径压缩的 weighted-quick-union 实现
 */

#include <iostream>
#include <stack>
#include <vector>

#ifndef UNION_FIND_SET_HPP
#define UNION_FIND_SET_HPP

class UnionFindSet {
private:
    std::vector<int> connection;
    std::vector<int> weight;
    int theCount;

public:
    UnionFindSet(int count);

    int count() const { return theCount; }

    int size() const { return connection.size(); }

    bool connected(int p, int q) { return find(p) == find(q); }

    friend std::ostream &operator<<(std::ostream &out, const UnionFindSet &set);

    int find(int index);

    void connect(int p, int q);
};

UnionFindSet::UnionFindSet(int count) {
    theCount = count;
    for (int i = 0; i < count; i++) {
        connection.push_back(i);
        weight.push_back(1);
    }
}

int UnionFindSet::find(int index) {
    std::stack<int> path{};
    while (connection[index] != index) {
        path.push(index);
        index = connection[index];
    }
    while (!path.empty()) {
        connection[path.top()] = index;
        path.pop();
    }

    return index;
}

void UnionFindSet::connect(int p, int q) {
    if (!connected(p, q)) {
        int p_root = find(p);
        int q_root = find(q);

        if (p_root == q_root)
            return;

        if (weight[p_root] < weight[q_root]) {
            connection[p_root] = q_root;
            weight[q_root] += weight[p_root];
        } else {
            connection[q_root] = p_root;
            weight[p_root] += weight[q_root];
        }
    }
}

std::ostream &operator<<(std::ostream &out, const UnionFindSet &set) {
    out << set.connection[0];
    for (int i = 1; i < set.size(); i++) {
        out << " " << set.connection[i];
    }
    return out;
}
#endif