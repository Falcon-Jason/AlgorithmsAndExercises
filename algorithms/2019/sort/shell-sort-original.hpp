/*
 * @file: shell-sort-original.hpp
 * @brief: 希尔排序 一般实现（使用 3n+1 递增序列）
 */
#pragma once

#include <functional>
#include <algorithm>

namespace sort
{
template <class T, class Compare = std::less<T>>
void ShellSort_Original(T *begin, T *end, Compare cmp = Compare())
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
            for (auto j = i; j >= begin + height && cmp(*j, *(j - height)); j -= height)
            {
                swap(*j, *(j - height));
            }
        }
    }
}
} // namespace sort
