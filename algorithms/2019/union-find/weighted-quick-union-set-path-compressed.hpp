/**
 * @file: weighted-quick-union-set-path-compressed.hpp
 * @brief: 并查集之路径压缩的 weighted-quick-union 实现
 */

#include "union-find-set.hpp"
#include <vector>
#include <stack>

#ifndef PATH_COMPRESSED_WEIGHTED_QUICK_UNION_SET_HPP
#define PATH_COMPRESSED_WEIGHTED_QUICK_UNION_SET_HPP

class WeightedQuickUnionSet_PathCompressed : public UnionFindSet
{
    std::vector<int> weight;

public:
    WeightedQuickUnionSet_PathCompressed(int size) : UnionFindSet(size)
    {
        for (int i = 0; i < size; i++)
        {
            weight.push_back(1);
        }
    }

    int find(int index)
    {
        std::stack<int> path{};
        while (connection[index] != index)
        {
            path.push(index);
            index = connection[index];
        }
        while(!path.empty())
        {
            connection[path.top()] = index;
            path.pop();
        }

        return index;
    }

    void connect(int p, int q)
    {
        if (!connected(p, q))
        {
            int p_root = find(p);
            int q_root = find(q);

            if (p_root == q_root)
                return;

            if (weight[p_root] < weight[q_root])
            {
                connection[p_root] = q_root;
                weight[q_root] += weight[p_root];
            }
            else
            {
                connection[q_root] = p_root;
                weight[p_root] += weight[q_root];
            }
        }
    }
};

#endif