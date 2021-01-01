/*
 * @file: benchmark.cpp
 * @brief: 各排序算法的用时测试
 */

#include "sort.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace sort;
using namespace std;

static clock_t begin_time;
#define reset_time() (begin_time = clock());
#define get_time() (clock() - begin_time);

#define RAND_SEED 704387390
#define REPEATING_ELEM

#ifdef REPEATING_ELEM
#define RAND() rand()
#else
#define RAND() ((rand() << 16) + rand())
#endif

#define SORTBENCHMARK(SIZE, SORTFUNC, NAME, TIMES, CMP) \
    {                                                   \
        int *tmp = new int[SIZE];                       \
        srand(RAND_SEED);                               \
        cout << NAME << ":\t";                          \
                                                        \
        for (int i = 0; i < TIMES; i++)                 \
        {                                               \
            for (int i = 0; i < SIZE; i++)              \
            {                                           \
                tmp[i] = RAND();                        \
            }                                           \
                                                        \
            reset_time();                               \
            SORTFUNC(tmp, tmp + SIZE, CMP);             \
            clock_t ans = get_time();                   \
            if (!is_sorted(tmp, tmp + size, CMP))       \
                cout << "failed"                        \
                     << "\t";                           \
            else                                        \
                cout << ans << "\t";                    \
        }                                               \
        cout << endl;                                   \
        delete[] tmp;                                   \
    }

int main()
{
    int size = 10'000;
    int times = 10;
    greater<int> cmp{};
    SORTBENCHMARK(size, SelectionSort, "Selection Sort", times, cmp);
    SORTBENCHMARK(size, InsertionSort, "Insertion Sort", times, cmp);
    SORTBENCHMARK(size, ShellSort_Original, "Shell Sort Ori", times, cmp);
    SORTBENCHMARK(size, ShellSort, "Shell Sort", times, cmp);
    SORTBENCHMARK(size, MergeSort, "Merge Sort", times, cmp);
    SORTBENCHMARK(size, MergeSort_ButtonUp, "Merge Sort BU", times, cmp);
    SORTBENCHMARK(size, QuickSort_Original, "Quick Sort Ori", times, cmp);
    SORTBENCHMARK(size, QuickSort, "Quick Sort", times, cmp);
    SORTBENCHMARK(size, QuickSort_TriWay, "Quick Sort 3W", times, cmp);
    SORTBENCHMARK(size, QuickSort_QuickTriWay, "Quick Sort Q3W", times, cmp);
    SORTBENCHMARK(size, HeapSort, "Heap Sort", times, cmp);
    SORTBENCHMARK(size, std::sort, "STL Sort", times, cmp);
}