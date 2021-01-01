/*
 * @file: quick-sort-triway.hpp
 * @brief: 快速排序 三向切分实现
 */

#pragma once

#include <functional>
#include "insertion-sort.hpp"
#include "median.hpp"
#include <algorithm>

namespace sort
{
template <class T, class Compare = std::less<T>>
void QuickSort_TriWay(T *begin, T *end, Compare cmp = Compare())
{
    using namespace std;
    using namespace quicksort;
    
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
    // T &val = *begin;
    T *lower = begin;
    T *higher = end - 1;
    T *i = begin + 1;
    while (i <= higher)
    {
        if (cmp(*i, *lower))
        {
            swap(*lower, *i);
            ++lower;
            ++i;
        }
        else if (cmp(*lower, *i))
        {
            swap(*i, *higher);
            --higher;
        }
        else
        {
            ++i;
        }
    }

    QuickSort_TriWay(begin, lower, cmp);
    QuickSort_TriWay(higher + 1, end, cmp);
}
} // namespace sort