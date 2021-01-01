#include <iostream>
using namespace std;

void partition(int *begin, int *end, int *&p, int *&q) {
    int *i = begin;
    int *j = end + 1;
    p = begin + 1;
    q = end;

    for (;;) {
        while (p <= q && *p <= *begin) {
            if (*p == *begin) {
                i += 1;
                swap(*i, *p);
            }
            p += 1;
        }

        while (p <= q && *q >= *begin) {
            if (*q == *begin) {
                j -= 1;
                swap(*j, *q);
            }
            q -= 1;
        }
        if (p > q) {
            break;
        }

        swap(*p, *q);
        p += 1;
        q -= 1;
    }

    for (auto t = i; i >= begin && q >= t; i--, q--) {
        swap(*i, *q);
    }
    for (auto t = j; j <= end && p <= t; j++, p++) {
        swap(*j, *p);
    }
}

void quicksort(int *begin, int *end) {
    if (begin >= end) {
        return;
    }

    int *p, *q;
    partition(begin, end, p, q);
    quicksort(begin, q);
    quicksort(p, end);
}

void quicksort(int *arr, int size) {
    return quicksort(arr, arr + size - 1);
}

int main(int argc, char const *argv[]) {
    int arr[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int size = sizeof(arr) / sizeof(int);
    quicksort(arr, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
