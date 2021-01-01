#include <iostream>
#include <vector>

#define MAXN 100
using namespace std;

inline int gcd(int m, int n)
{
    return n == 0 ? m : gcd(n, m % n);
}

int packageAvailable[128];
bool packagable[11000];

int programmingUnpackagable();

int main()
{
    int packageCount;
    
    cin >> packageCount;
    for (int i = 0; i < packageCount;i++)
    {
        cin >> packageAvailable[i];
    }

    int commonGcd = packageAvailable[0];
    for (int i = 1; i < packageCount;i++)
    {
        commonGcd = gcd(commonGcd, packageAvailable[i]);
    }

    if(commonGcd != 1)
    {
        cout << "INF" << endl;
        return 0;
    }

    packagable[0] = true;
    for (int i = 0; i < packageCount;i++)
    {
        for (int j = 0; j <= 10000 - packageAvailable[i];j++)
        {
            if(packagable[j])
            {
                packagable[j + packageAvailable[i]] = true;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i < 10000;i++)
    {
        if(!packagable[i])
        {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}