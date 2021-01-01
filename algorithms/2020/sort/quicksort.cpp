#include <iostream>
using namespace std;

int *partition(int *begin, int *end) {
    int *p = begin + 1;
    int *q = end;

    for (;;) {
        while (p <= q && *p < *begin) {
            p++;
        }

        while (p <= q && *q > *begin) {
            q--;
        }
        if (p > q) {
            break;
        }
        swap(*p, *q);
        p++;
        q--;
    }
    swap(*(p - 1), *begin);
    return p - 1;
}

void quicksort(int *begin, int *end) {
    if (begin >= end) {
        return;
    }

    int *p = partition(begin, end);

    quicksort(begin, p - 1);
    quicksort(p + 1, end);
}

void quicksort(int *arr, int size) {
    return quicksort(arr, arr + size - 1);
}

int main(int argc, char const *argv[]) {
    int arr[] = {4, 8, 7, 1, 3, 5, 6, 2};
    int size = sizeof(arr) / sizeof(int);
    quicksort(arr, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
