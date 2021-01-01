/*
 * @file: heap-sort.hpp
 * @brief: 堆排序 实现
 */

#pragma once

#include <functional>
#include <algorithm>

namespace sort
{
namespace heapsort
{
template <class T, class Compare>
void sink(T* base, int size, int k, Compare cmp)
{
    using namespace std;
    while (((k << 1) | 1) < size)
    {
        int i = ((k << 1) | 1);
        if (i < size - 1 && cmp(base[i], base[i + 1]))
            ++i;

        if (!cmp(base[k], base[i]))
        {
            break;
        }
        swap(base[k], base[i]);
        k = i;
    }
}
} // namespace heapsort

template <class T, class Compare = std::less<T>>
void HeapSort(T *begin, T *end, Compare cmp = Compare())
{
    using namespace std;
    using namespace heapsort;

    int size = end - begin;
    for (int i = size / 2; i >= 0; --i)
    {
        sink(begin, size, i, cmp);
    }

    while(size > 0)
    {
        swap(*begin, begin[--size]);
        sink(begin, size, 0, cmp);
    }
}
} // namespace sort