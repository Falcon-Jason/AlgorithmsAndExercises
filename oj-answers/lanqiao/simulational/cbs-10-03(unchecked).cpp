#include <iostream>

using namespace std;
int max_callaz(int n)
{
    int max = 1;

    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = n * 3 + 1;
        }

        if (n > max)
        {
            max = n;
        }
    }
    return max;
}
int main()
{
    int range;
    int max = 1;
    cin >> range;
    for (int i = 1; i <= range; i++)
    {
        int n = max_callaz(i);
        if (n > max)
        {
            max = n;
        }
    }

    cout << max << endl;
}