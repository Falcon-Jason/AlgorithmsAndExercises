/**
 * @file: quick-union-set.hpp
 * @brief: 并查集之 quick-union 实现
 */

#include "union-find-set.hpp"

#ifndef QUICK_UNION_SET_HPP
#define QUICK_UNION_SET_HPP

class QuickUnionSet : public UnionFindSet
{
public:
    QuickUnionSet(int size) : UnionFindSet(size){};

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
            connection[find(p)] = find(q);
            count_--;
        }
    }
};

#endif