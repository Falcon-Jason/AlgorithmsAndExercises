/**
 * @file: quick-find-set.hpp
 * @brief: 并查集之 quick-find 实现
 */

#include <iostream>
#include <vector>
#include "union-find-set.hpp"

#ifndef QUICK_FIND_SET_HPP
#define QUICK_FIND_SET_HPP

class QuickFindSet : public UnionFindSet
{
public:
    QuickFindSet(int size) : UnionFindSet(size){};

    int find(int index)
    {
        return connection[index];
    }

    void connect(int p, int q)
    {
        if(connected(p,q))
            return;

        for (int i = 0; i < count_; i++)
        {
            int pid = find(p);
            int qid = find(q);

            if(pid == qid)
                return;

            for (int i = 0; i < size(); i++)
            {
                if(connection[i] == pid)
                    connection[i] = qid;
            }
            count_--;
        }
        count_--;
    }    
};

#endif