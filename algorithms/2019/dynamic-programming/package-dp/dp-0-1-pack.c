/* 动态规划 求解0/1背包问题 */
#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAX_SIZE 255

int size;
int max_weight;
int values[MAX_SIZE];
int weights[MAX_SIZE];
int max_values[MAX_SIZE][MAX_SIZE];

int dynamic_programming()
{
    for (int i = 0; i <= size; i++)
    {
        max_values[i][0] = 0;
    }

    for (int w = 0; w <= max_weight; w++)
    {
        max_values[0][w] = 0;
    }

    for (int i = 1; i <= size; i++)
    {
        for (int w = 1; w <= max_weight; w++)
        {
            if (weights[i] > w)
            {
                max_values[i][w] = max_values[i - 1][w];
            }
            else
            {
                max_values[i][w] = max(max_values[i - 1][w],
                                       max_values[i - 1][w - weights[i]] + values[i]);
            }
        }
    }

    return max_values[size][max_weight];
}

int *get_chosen()
{
    static int chosen[MAX_SIZE];

    memset(chosen, 0, sizeof(chosen));
    for (int i = size, w = max_weight; i >= 0; i--)
    {
        if (max_values[i][w] != max_values[i - 1][w])
        {
            ++chosen[i];
            w = w - weights[i];
        }
    }
    return chosen;
}

int main()
{
    int max_value;
    scanf("%d%d", &size, &max_weight);

    for (int i = 1; i <= size; i++)
    {
        scanf("%d", &weights[i]);
    }

    for (int i = 1; i <= size; i++)
    {
        scanf("%d", &values[i]);
    }

    max_value = dynamic_programming();

    int *chosen = get_chosen();

    for (int i = 1; i <= size; i++)
    {
        printf("%d ", chosen[i]);
    }

    printf("\n%d\n", max_value);

    return 0;
}