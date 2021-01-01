#include <stdio.h>

double QuickPow(double base, int index);

int main(int argc, char const *argv[])
{
    double a;
    int b;
    while (scanf("%lf%d", &a, &b) == 2)
    {
        printf("%.2f ^ %d = %.2f\n", a, b, QuickPow(a, b));
    }
    return 0;
}

#ifdef RECURSIVE
double QuickPow(double base, int index)
{
    if (index == 0 || base == 1)
        return 1;

    if (index == 1)
        return base;
    else if (index & 1)
        return QuickPow(base * base, index / 2) * base;
    else
        return QuickPow(base * base, index / 2);
}
#else
static inline int LogFloor(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i *= 2)
    {
        ans++;
    }
    return ans;
}

double QuickPow(double base, int index)
{
    if (index == 0 || base == 1)
        return 1;

    int stksize = LogFloor(index);
    double stack[stksize];
    int stkptr = 0;

    for (; index != 1; index /= 2)
    {
        if (index & 1)
        {
            stack[stkptr++] = base;
        }
        base *= base;
    }
    while (stkptr != 0)
    {
        base *= stack[--stkptr];
    }

    return base;
}
#endif