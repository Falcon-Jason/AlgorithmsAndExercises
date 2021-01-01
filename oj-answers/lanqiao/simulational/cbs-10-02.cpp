#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i * i + j * j < n; j++)
        {
            for (int k = 0; i * i + j * j + k * k < n; k++)
            {
                for (int l = 1; i * i + j * j + k * k + l * l <= n; l++)
                {
                    if (i * i + j * j + k * k + l * l == n)
                    {
                        printf("%d %d %d %d\n", i, j, k, l);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}