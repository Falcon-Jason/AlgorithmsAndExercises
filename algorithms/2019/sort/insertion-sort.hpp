/*
 * @file: insertion-sort.hpp
 * @brief: 插入排序 实现
 */

#pragma once

#include <functional>

namespace sort
{
template <class T, class Compare = std::less<T>>
void InsertionSort(T *begin, T *end, Compare cmp = Compare())
{
    for (auto i = begin + 1; i < end; ++i)
    {
        auto key = *i;
        auto j = i - 1;
        for (; j >= begin && !cmp(*j, key); --j)
        {
            *(j + 1) = *j;
        }
        *(j + 1) = key;
    }
}
} // namespace sort