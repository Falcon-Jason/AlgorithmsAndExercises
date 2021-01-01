/**
 * @file: test.cpp
 * @brief: 并查集 动态连通性问题测试 (详见<<算法: 第四版>>)
 */

#include <iostream>
#include "quick-find-set.hpp"
#include "quick-union-set.hpp"
#include "weighted-quick-union-set.hpp"
#include "weighted-quick-union-set-path-compressed.hpp"
using namespace std;

int main()
{
    int size;
    int connects;

    cin >> size >> connects;

    WeightedQuickUnionSet_PathCompressed set{size};

    for (int i = 0; i < connects; i++)
    {
        int m, n;
        cin >> m >> n;
        // cout << set << endl;
        if(!set.connected(m,n))
        {
            set.connect(m, n);
            cout << m << " " << n << endl;
        }
        // cout << set << endl;
    }
    return 0;
}