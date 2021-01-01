/* 动态规划求解 数字三角形求最大路径上的和 递归实现 */
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50
#define UNSOLVED -1

int data[MAX_SIZE][MAX_SIZE];
int max[MAX_SIZE][MAX_SIZE];
int size;

int max_sum(int i,int j);

int main()
{
    scanf("%d", &size);

    memset(max, UNSOLVED, sizeof(max));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            scanf("%d", &data[i][j]);
        }
    }

    printf("%d\n", max_sum(0, 0));
    return 0;
}

int max_sum(int i, int j)
{
    int l_sum, r_sum;

    if(i == size-1)
    {
        return data[i][j];
    }

    if(max[i+1][j] == UNSOLVED)
    {
        max[i + 1][j] = max_sum(i + 1, j);
    }

    if(max[i+1][j+1] == UNSOLVED)
    {
        max[i + 1][j + 1] = max_sum(i + 1, j + 1);
    }

    l_sum = max[i + 1][j] + data[i][j];
    r_sum = max[i + 1][j + 1] + data[i][j];

    return l_sum > r_sum ? l_sum : r_sum;
}
