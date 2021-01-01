/*
 * @file: shell-sort.hpp
 * @brief: 希尔排序 经过优化的实现（使用 3n+1 递增序列）
 */
#pragma once

#include <algorithm>
#include <functional>

namespace sort
{
template <class T, class Compare = std::less<T>>
void ShellSort(T *begin, T *end, Compare cmp = Compare())
{
    using namespace std;
    
    size_t size = end - begin;

    // generate increment sequence
    size_t height = 1;
    while (height < size / 3)
    {
        height = height * 3 + 1;
    }

    // shell sorting

    for (; height >= 1; height /= 3)
    {
        for (auto i = begin + height; i < end; ++i)
        {
            auto tmp = *i;
            auto j = i - height;
            for (; j >= begin && j < end && cmp(tmp, *j); j -= height)
            {
                *(j + height) = *j;
            }
            *(j + height) = tmp;
        }
    }
}
} // namespace shellsort
