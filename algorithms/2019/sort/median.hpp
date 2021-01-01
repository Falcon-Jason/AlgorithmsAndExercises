/*
 * @file: median.hpp
 * @brief: 取三向中位数函数的实现，用于快速排序的三取样
 */

#pragma once

#include <functional>

namespace sort::quicksort
{
template <class T, class Compare>
T *Median(T *a, T *b, T *c, Compare cmp)
{
    if (cmp(*a, *b))
    {
        if (cmp(*b, *c))
        {
            return b;
        }
        else if (cmp(*c, *a))
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if (cmp(*b, *c))
        {
            return b;
        }
        else if (cmp(*c, *a))
        {
            return a;
        }
        else
        {
            return c;
        }
    }
}
} // namespace sort::quicksorting