/* 动态规划求解 数字三角形求最小路径和最小路径上的和 循环实现 */
#include <stdio.h>
#include <string.h>

#define LEFT 0
#define RIGHT 1
#define MAX_SIZE 255

int data[MAX_SIZE][MAX_SIZE];
int size;

int dp[MAX_SIZE][MAX_SIZE];
int post[MAX_SIZE][MAX_SIZE];

void search()
{
    for (int j = 0; j < size;j++)
    {
        dp[size - 1][j] = data[size - 1][j];
    }

    for (int i = size - 1; i > 0;i--)
    {
        for (int j = 0; j < i;j++)
        {
            if (dp[i][j] < dp[i][j + 1])
            {
                dp[i - 1][j] = dp[i][j] + data[i - 1][j];
                post[i - 1][j] = LEFT;
            }

            else
            {
                dp[i - 1][j] = dp[i][j + 1] + data[i - 1][j];
                post[i - 1][j] = RIGHT;
            }
        }
    }
}

void disp_path()
{
    int i = 0;
    int j = 0;
    while(i<size)
    {
        printf("%d ", data[i][j]);
        j = j + post[i][j];
        i++;
    }
    printf("\n");
}

int main()
{
    // int k;
    memset(post, 0, sizeof(post));
    memset(dp, 0, sizeof(dp));
    scanf("%d", &size);

    for (int i = 0; i < size;i++)
    {
        for (int j = 0; j <= i;j++)
        {
            scanf("%d", &data[i][j]);
        }
    }

    search();
    disp_path();
    printf("%d\n", dp[0][0]);
    return 0;
}