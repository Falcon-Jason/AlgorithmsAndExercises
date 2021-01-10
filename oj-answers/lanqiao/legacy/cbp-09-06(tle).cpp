#include <iostream>
#include <algorithm>

using namespace std;
#define MAXN 110000
int arraySize;
int arrays[3][MAXN];
int dp[3][MAXN];

int search(int *array, int n)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] >= n)
        {
            return i + 1;
        }
    }
    return arraySize;
}

int dpIncreasing()
{
    for (int i = 0; i < arraySize; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            dp[i][j] = search(arrays[i - 1], arrays[i][j]) * dp[i - 1][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < arraySize; i++)
    {
        sum += dp[2][i];
    }
    return sum;
}

int main()
{
    cin >> arraySize;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            cin >> arrays[i][j];
        }
        sort(arrays[i], arrays[i] + arraySize);
    }
    
    cout << dpIncreasing() << endl;
    return 0;
}