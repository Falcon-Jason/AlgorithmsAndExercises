/**
 * @file: weighted-quick-union-set.hpp
 * @brief: 并查集之 weighted-quick-union 实现
 */

#include "union-find-set.hpp"
#include <vector>

#ifndef WEIGHTED_QUICK_UNION_SET_HPP
#define WEIGHTED_QUICK_UNION_SET_HPP

class WeightedQuickUnionSet : public UnionFindSet
{
    std::vector<int> weight;

public:
    WeightedQuickUnionSet(int size) : UnionFindSet(size)
    {
        for (int i = 0; i < size; i++)
        {
            weight.push_back(1);
        }
    }

    int find(int index)
    {
        while (connection[index] != index)
            index = connection[index];

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