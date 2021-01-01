#include <iostream>
#include <algorithm>

using namespace std;

int callaz_c[2000000] = {0};

int callaz(int n)
{
    if(callaz_c[n] != 0)
    {
        return callaz_c[n];
    }
    long long m = n;
    int i = 1;
    while (m != 1)
    {
        if (m & 1)
        {
            m = 3 * m + 1;
        }
        else
        {
            m /= 2;
        }
        i++;    
    }

    return callaz_c[n] = i;
}

int main()
{
    int begin, end, maxc;
    while (cin >> begin >> end)
    {
        int real_begin = min(begin, end);
        int read_end = max(begin, end);
        maxc = 0;
        for (int i = real_begin; i <= read_end; i++)
        {
            int n = callaz(i);
            if (n > maxc)
            {
                maxc = n;
            }
        }
        cout << begin << " " << end << " " << maxc << endl;
    }
    return 0;
}

// Accepted: https://vjudge.net/solution/17961040
// After Optimized: https://vjudge.net/solution/17961127