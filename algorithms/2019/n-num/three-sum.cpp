#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int size;
    int *arr;
    int count = 0;
    cin >> size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + size);
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            int *place = find(arr, arr + size, -arr[i] - arr[j]);
            if (place > arr + j && place < arr + size)
            {
                count++;
            }
        }
    }
    cout << count << endl;
    delete[] arr;
    return 0;
}