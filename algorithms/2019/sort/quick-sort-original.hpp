/*
 * @file: quick-sort-original.hpp
 * @brief: 快速排序 原始简单实现（基于K&R 函数递归部分）
 */

#pragma once

#include <functional>
#include "insertion-sort.hpp"
#include <algorithm>

namespace sort
{
template <class T, class Compare = std::less<T>>
void QuickSort_Original(T *begin, T *end, Compare cmp = Compare())
{
    using namespace std;
    if (end <= begin)
    {
        return;
    }

    T *mid = begin + (end - begin) / 2;
    swap(*begin, *mid);

    T *lo = begin;

    for (T *i = begin + 1; i < end; i++)
    {
        if (cmp(*i, *begin))
        {
            swap(*(++lo), *i);
        }
    }

    swap(*begin, *(lo));
    QuickSort_Original(begin, lo, cmp);
    QuickSort_Original(lo + 1, end, cmp);
}
} // namespace sort