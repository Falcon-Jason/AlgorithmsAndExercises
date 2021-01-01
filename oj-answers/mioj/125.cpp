#include <iostream>

using namespace std;

int main()
{
    long long n, l;
    cin >> n >> l;
    long long i = 0;
    if (n & 1)
    {
        if (l & 1)
        {
            i = min(n - l, l);
        }
        else
        {
            i = -1;
        }
    }
    else
    {
        if (l & 1)
        {
            i = l;
        }
        else
        {
            i = n - l;
        }
    }
    if (i == -1)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        cout << i << endl;
    }
    return 0;
}