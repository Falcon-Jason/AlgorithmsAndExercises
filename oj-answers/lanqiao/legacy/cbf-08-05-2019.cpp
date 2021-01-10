#include <iostream>
#include <algorithm>
#define CAPACITY 110000
using namespace std;

int computeMaxUnmatchable(int *values, int size, int interval);
int maxDifferent(int *values, int size);

int main()
{
    int *values = new int[CAPACITY]{0};
    int count, interval;
    int userScore;
    int maxScore = 0;
    cin >> count >> interval;
    for (int i = 0; i < count;i++)
    {
        cin >> userScore;
        ++values[userScore];
        if(userScore > maxScore)
        {
            maxScore = userScore;
        }
    }
    cout << computeMaxUnmatchable(values, maxScore + 1, interval) << endl;
    delete[] values;
}

int computeMaxUnmatchable(int* values, int size, int interval)
{
    if(interval == 0)
    {
        return maxDifferent(values, size);
    }
    int *dp = new int[size]{0};
    for (int i = 0; i <= 2 * interval - 1;i++)
    {
        dp[i] = values[i];
    }
    for (int i = 2 * interval; i < size;i++)
    {
        dp[i] = max(dp[i - interval], dp[i - 2 * interval] + values[i]);
    }
    int maxUnmatchable = 0;
    for (int i = 1; i <= interval;i++)
    {
        maxUnmatchable += dp[size - i];
    }

    delete[] dp;
    return maxUnmatchable;
}

int maxDifferent(int *values, int size)
{
    int n = 0;
    for (int i = 0; i < size;i++)
    {
        if(values[i])
            n++;
    }
    return n;
}

// Accepted: http://lx.lanqiao.cn/detail.page?submitid=3692162