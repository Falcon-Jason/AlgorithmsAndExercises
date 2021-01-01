#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 4
#define EMPTY 0
#define WALL 1
#define FIRE 2
using namespace std;

int mapSize;
int fireNet[MAXN][MAXN];

void readFireNet()
{
    int n;
    cin.get();
    for (int i = 0; i < mapSize; i++)
    {
        for (int j = 0; j < mapSize; j++)
        {
            n = cin.get();
            fireNet[i][j] = n == '.' ? EMPTY : WALL;
        }
        cin.get();
    }
}

bool placable(int x, int y)
{
    for (int i = x; i >= 0 && fireNet[i][y] != WALL; i--)
    {
        if (fireNet[i][y] == FIRE)
            return false;
    }
    for (int i = x; i < mapSize && fireNet[i][y] != WALL; i++)
    {
        if (fireNet[i][y] == FIRE)
            return false;
    }
    for (int j = y; j >= 0 && fireNet[x][j] != WALL; j--)
    {
        if (fireNet[x][j] == FIRE)
            return false;
    }
    for (int j = y; j < mapSize && fireNet[x][j] != WALL; j++)
    {
        if (fireNet[x][j] == FIRE)
            return false;
    }
    return true;
}

int searchingMaxCount(const int beginRow = 0, const int beginCol = 0)
{
    if (beginRow == mapSize)
    {
        int count = 0;
        for (int i = 0; i < mapSize; i++)
        {
            for (int j = 0; j < mapSize; j++)
            {
                if (fireNet[i][j] == FIRE)
                {
                    count++;
                }
            }
        }
        return count;
    }
    if (fireNet[beginRow][beginCol] == EMPTY && placable(beginRow, beginCol))
    {
        fireNet[beginRow][beginCol] = FIRE;
        int maxCount = searchingMaxCount(beginRow + (beginCol + 1) / mapSize, (beginCol + 1) % mapSize);
        fireNet[beginRow][beginCol] = EMPTY;
        return max(maxCount, searchingMaxCount(beginRow + (beginCol + 1) / mapSize, (beginCol + 1) % mapSize));
    }

    return searchingMaxCount(beginRow + (beginCol + 1) / mapSize, (beginCol + 1) % mapSize);
}

int main()
{
    while (cin >> mapSize && mapSize != 0)
    {
        readFireNet();
        cout << searchingMaxCount() << endl;
    }
    return 0;
}

// Accepted: https://vjudge.net/solution/18575063