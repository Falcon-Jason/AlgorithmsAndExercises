/*
 * @file: merge-sort-buttonup.hpp
 * @brief: 归并排序 自底向上实现
 */

#pragma once

#include <functional>
#include "insertion-sort.hpp"
#include "merge.hpp"

namespace sort
{
template <class T, class Compare = std::less<T>>
void MergeSort_ButtonUp(T *begin, T *end, Compare cmp = Compare())
{
    using namespace mergesort;
    using namespace std;
    T *tmparr = new T[end - begin];
    int size = end - begin;
    
    for (int i = 1; i < size; i *= 2)
    {
        for (auto j = begin; j < end - i; j += 2 * i)
        {
            if (cmp(*(j + i), *(j + i - 1)))
                Merge(j, j + i, min(j + 2 * i, end), tmparr, cmp);
        }
    }
    delete[] tmparr;
}
} // namespace sort