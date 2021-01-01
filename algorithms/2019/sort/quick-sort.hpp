/*
 * @file: quick-sort.hpp
 * @brief: 快速排序 一般实现
 */

#pragma once

#include <functional>
#include "insertion-sort.hpp"
#include "median.hpp"
#include <algorithm>

namespace sort
{
template <class T, class Compare = std::less<T>>
void QuickSort(T *begin, T *end, Compare cmp = Compare())
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

    T *lower = begin + 1;
    T *higher = end - 1;

    swap(*begin, *mid);
    for (;;)
    {
        while (lower <= higher && !cmp(*begin, *lower))
        {
            ++lower;
        }

        while (lower <= higher && !cmp(*higher, *begin))
        {
            --higher;
        }

        if (lower > higher)
            break;
        swap(*lower, *higher);
    }

    swap(*begin, *(lower - 1));
    QuickSort(begin, lower - 1, cmp);
    QuickSort(lower, end, cmp);
}
} // namespace sort