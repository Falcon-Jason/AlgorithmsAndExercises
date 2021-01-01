/* 
 * 动态规划 求解完全背包问题 改进版
 * 采用一维数组实现，空间复杂度由原本的O(VN) 降至O(V)
 * 抽象出函数dpFullPack(int*,int,int) 使程序更加结构化 可读可移植
 * 无法回推得到最优解
 */

#include <iostream>
#include <algorithm>
#define MAX_SIZE 128
#define DEFAULT 0

int count;
int maxWeight;

void printArray(int *, int);
void readArray(int *, int);
void setArray(int *, int, int);

int dpFullPack(int *, int, int);

int main()
{
    int maxValue = 0;
    std::cin >> count >> maxWeight;
    int *weights = new int[count + 1];
    int *values = new int[count + 1];
    int *dpFunction = new int[maxWeight + 1];
    weights[0] = values[0] = dpFunction[0] = 0;

    readArray(weights + 1, count);
    readArray(values + 1, count);
    setArray(dpFunction + 1, 0, maxWeight);
    
    for (int i = 1; i <= count; i++)
    {
        maxValue = dpFullPack(dpFunction,weights[i],values[i]);
    }

    std::cout << maxValue << std::endl;

    delete[] weights;
    delete[] values;
    delete[] dpFunction;

    return 0;
}

int dpFullPack(int *dpFunc, int weight, int value)
{
    for (int w = maxWeight; w >= weight; w--)
    {
        for (int k = 0; k * weight <= w; k++)
        {
            dpFunc[w] = std::max(dpFunc[w], dpFunc[w - k * weight] + k * value);
        }
    }
    
    return dpFunc[maxWeight];
}

void readArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void setArray(int *array, int value, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = value;
    }
}