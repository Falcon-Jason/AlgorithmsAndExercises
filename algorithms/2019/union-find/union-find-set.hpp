/**
 * @file: union-find-set.hpp
 * @brief: 并查集ADT与基本函数实现
 */

#include <iostream>
#include <vector>

#ifndef UNION_FIND_SET_HPP
#define UNION_FIND_SET_HPP

class UnionFindSet
{
protected:
    std::vector<int> connection;
    int count_;

public:
    UnionFindSet(int count);

    int count() const { return count_; }

    int size() const { return connection.size(); }

    bool connected(int p, int q) { return find(p) == find(q); }

    friend std::ostream &operator<<(std::ostream &out, const UnionFindSet &set);

    virtual int find(int index) = 0;

    virtual void connect(int p, int q) = 0;
};

UnionFindSet::UnionFindSet(int count)
{
    count_ = count;
    for (int i = 0; i < count; i++)
    {
        connection.push_back(i);
    }
}

std::ostream &operator<<(std::ostream &out, const UnionFindSet &set)
{
    out << set.connection[0];
    for (int i = 1; i < set.size(); i++)
    {
        out << " " << set.connection[i];
    }
    return out;
}
#endif