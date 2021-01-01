/* 动态规划 求解 完全背包问题 */
#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define less(a, b) ((a) < (b))
#define sum(a, b) ((a) + (b))
#define let(a, b) ((a) = (b))
#define MAX_SIZE 255

int size;
int max_weight;
int values[MAX_SIZE];
int weights[MAX_SIZE];
int max_values[MAX_SIZE][MAX_SIZE];
int the_chosens[MAX_SIZE][MAX_SIZE];

int dynamic_programming()
{
    for (int i = 0; i < size; i++)
    {
        max_values[i][0] = 0;
    }

    for (int w = 0; w < size; w++)
    {
        max_values[0][w] = 0;
    }

    for (int i = 1; i <= size; i++)
    {
        for (int w = 1; w <= max_weight; w++)
        {
            max_values[i][w] = max_values[i - 1][w];
            if (weights[i] <= w)
            {
                for (int k = 1; k * weights[i] <= w; k++)
                {
                    if (
                        less(
                            max_values[i][w],
                            max_values[i - 1][w - k * weights[i]] + k * values[i]))
                    {
                        let(
                            max_values[i][w],
                            sum(
                                max_values[i - 1][w - k * weights[i]],
                                k * values[i]));
                        let(
                            the_chosens[i][w],
                            k);
                    }
                }
            }
        }
    }

    return max_values[size][max_weight];
}

int *get_chosen()
{
    static int chosen[MAX_SIZE];

    memset(chosen, 0, MAX_SIZE);
    for (int i = size, w = max_weight; i >= 0; i--)
    {
        if (max_values[i][w] != max_values[i - 1][w])
        {
            chosen[i] = the_chosens[i][w];
            w = w - weights[i] * chosen[i];
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

    memset(the_chosens, 0, sizeof(the_chosens));
    max_value = dynamic_programming();

    int *chosen = get_chosen();

    for (int i = 1; i <= size; i++)
    {
        printf("%d ", chosen[i]);
    }

    printf("\n%d\n", max_value);

    return 0;
}