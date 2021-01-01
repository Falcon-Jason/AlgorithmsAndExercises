#include <iostream>
#include <algorithm>

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

    sort(arr, arr + size, [](int a, int b) { return a <= b; });
    for (int i = 0; i < size; i++)
    {
        int *place = find(arr, arr + size, -arr[i]);
        if(place > arr+i && place<arr+size){
            count++;
        }
    }
    cout << count << endl;
    delete[] arr;
    return 0;
}