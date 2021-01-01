/*
 * @file: selection-sort.hpp
 * @brief: 选择排序 实现
 */

#pragma once

#include <functional>

namespace sort
{
template <class T, class Compare = std::less<T>>
void SelectionSort(T *begin, T *end, Compare cmp = Compare())
{
    using namespace std;

    for (auto i = begin; i < end; ++i)
    {
        auto min = i;
        for (auto j = i + 1; j < end; ++j)
        {
            if (cmp(*j, *min))
            {
                min = j;
            }
        }
        swap(*i, *min);
    }
}
} // namespace selectionsort