/*
 * @file: merge-sort.hpp
 * @brief: 归并排序 自顶向下递归实现
 */

#pragma once

#include <functional>
#include "insertion-sort.hpp"
#include "merge.hpp"

namespace sort
{
namespace mergesort
{
template <class T, class Compare = std::less<T>>
void MergeSort(T *begin, T *end, T *tmparr, Compare cmp = Compare())
{
    if (end <= begin)
        return;

    if (end - begin < 7)
    {
        InsertionSort(begin, end, cmp);
        return;
    }

    auto mid = begin + (end - begin) / 2;
    MergeSort(begin, mid, tmparr, cmp);
    MergeSort(mid, end, tmparr, cmp);
    if (cmp(*mid, *(mid - 1)))
    {
        Merge(begin, mid, end, tmparr, cmp);
    }
}
} // namespace mergesort

template <class T, class Compare>
void MergeSort(T *begin, T *end, Compare cmp)
{
    T *tmparr = new T[end - begin];
    mergesort::MergeSort(begin, end, tmparr, cmp);
    delete[] tmparr;
}
} // namespace sort