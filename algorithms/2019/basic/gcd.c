#include <stdio.h>

int gcd(int m, int n)
{
    int rem;

    while(n > 0)
    {
        rem = m % n;
        m = n;
        n = rem;
    }

    return m;
}

int main(int argc, char const *argv[])
{
    int m,n;
    scanf("%d%d",&m,&n);
    printf("%d\n",gcd(m,n));
    return 0;
}
