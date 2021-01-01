#include <iostream>
using namespace std;

void print_list(int *arr,int size)
{
    for (int i = 0; i < size;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool jump(int *arr,int size)
{
    // print_list(arr, size);
    if(size <= 1){
        return true;
    }
    for (int i = 1; i <= arr[0];i++){
        if(jump(arr+i,size-i))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[16];
    int i=0;
    while(cin >> arr[i++])
        ;
    cout << boolalpha << jump(arr, i-1);
}