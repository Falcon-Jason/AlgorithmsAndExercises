/* 动态规划求解 数字三角形求最大路径上的和 循环实现 */
#include <stdio.h>
#include <stdlib.h>

int max_sum(int *data[], int size);

int main()
{
    int size;
    scanf("%d", &size);

    int *data[size];

    for (int i = 0; i < size;i++)
    {
        data[i] = malloc(size * sizeof(int));
        for (int j = 0; j <= i; j++)
        {
            scanf("%d", &data[i][j]);
        }
    }

    int max = max_sum(data, size);
    printf("%d\n", max);

    for (int i = 0; i < size;i++)
    {
        free(data[i]);
    }
    return 0;
}

int max_sum(int *data[], int size)
{
    int max[size][size];

    for (int j = 0; j < size;j++)
    {
        max[size - 1][j] = data[size - 1][j];
    }

    for (int i = size - 1; i > 0;i--)
    {
        for (int j = 0; j < i;j++)
        {
            if (max[i][j] > max[i][j + 1])
            {
                max[i - 1][j] = max[i][j] + data[i - 1][j]; 
            }

            else
            {
                max[i - 1][j] = max[i][j + 1] + data[i - 1][j];
            }
        }
    }

    return max[0][0];
}
