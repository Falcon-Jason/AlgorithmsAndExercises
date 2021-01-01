/*
 * @file: merge.hpp
 * @brief: 二路归并的实现，用于归并排序
 */

#pragma once

#include <functional>
#include <algorithm>

namespace sort::mergesort
{
template <class T, class Compare = std::less<T>>
void Merge(T *begin, T *mid, T *end, T *tmparr, Compare cmp = Compare())
{
    for (auto i = begin; i < end; ++i)
    {
        tmparr[i - begin] = *i;
    }

    int imid = mid - begin;
    int iend = end - begin;

    int i = 0;
    int j = imid;

    for (auto k = begin; k < end; ++k)
    {
        if (j >= iend)
            *k = tmparr[i++];
        else if (i >= imid)
            *k = tmparr[j++];
        else if (cmp(tmparr[i], tmparr[j]))
            *k = tmparr[i++];
        else
            *k = tmparr[j++];
    }
}
} // namespace sort::mergesort
