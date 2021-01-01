#include <cstdio>

int p(int a, int d)
{
    int p = 0;
    while (a != 0)
    {
        if (a % 10 == d)
        {
            p *= 10;
            p += d;
        }
        a /= 10;
    }
    return p;
}

int main()
{
    int a1, a2, d1, d2;
    scanf("%d%d%d%d", &a1, &d1, &a2, &d2);
    printf("%d\n", p(a1, d1) + p(a2, d2));
    return 0;
}