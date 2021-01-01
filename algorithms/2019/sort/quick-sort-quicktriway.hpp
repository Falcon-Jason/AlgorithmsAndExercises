/*
 * @file: quick-sort-quicktriway.hpp
 * @brief: 快速排序 快速三向切分实现
 */

#pragma once

#include <functional>
#include "insertion-sort.hpp"
#include "median.hpp"
#include <algorithm>

namespace sort
{
template <class T, class Compare = std::less<T>>
void QuickSort_QuickTriWay(T *begin, T *end, Compare cmp = Compare())
{
    using namespace std;
    using namespace quicksort;
    
loop:
    if (end - begin < 7)
    {
        InsertionSort(begin, end, cmp);
        return;
    }

    T *mid = begin + (end - begin) / 2;

    if (end - begin > 7)
    {
        T *left = begin;
        T *right = end - 1;
        mid = Median(left, mid, right, cmp);
    }

    swap(*begin, *mid);
    T *a, *b, *c, *d;
    a = b = begin + 1;
    c = d = end - 1;

    for (;;)
    {
        while (b <= c && !cmp(*begin, *b))
        {
            if (!cmp(*b, *begin))
            {
                swap(*a, *b);
                a++;
            }
            b++;
        }
        while (b <= c && !cmp(*c, *begin))
        {
            if (!cmp(*begin, *c))
            {
                swap(*c, *d);
                d--;
            }
            c--;
        }
        if (b > c)
            break;
        swap(*b, *c);
        b++;
        c--;
    }

    T *m = begin;
    T *n = c;
    while (m < a && m < n)
    {
        swap(*m, *n);
        m++;
        n--;
    }
    m = end - 1;
    n = b;
    while (m > d && m > n)
    {
        swap(*m, *n);
        m--;
        n++;
    }

    int da = b - a;
    int db = d - c;

    if (da <= db)
    {
        if (da > 1)
        {
            QuickSort_QuickTriWay(begin, begin + da, cmp);
        }
        if (db > 1)
        {
            begin = end - db;
            goto loop;
        }
    }
    else
    {
        if (db > 1)
        {
            QuickSort_QuickTriWay(end - db, end, cmp);
        }
        if (da > 1)
        {
            end = begin + da;
            goto loop;
        }
    }
}
} // namespace sort