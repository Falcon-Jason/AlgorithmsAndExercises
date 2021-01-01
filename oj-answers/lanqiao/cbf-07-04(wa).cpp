#include <iostream>
using namespace std;
#define MAX_SIZE 50

int tower[MAX_SIZE][MAX_SIZE];

int computeMethod(int cntA, int cntB, int size, int i);
bool isAvailable(int cntA, int cntB, int size);

int towerSize(int total)
{
    const static int sizes[MAX_SIZE] = {
        1,    3,   6,  10, 15,
        21,  28,  36,  45, 55,
        66,  78,  91, 105, 120,
        136, 153, 171, 190, 210,
        231, 253, 276, 300, 325,
        351, 378, 406, 435, 465, 
        496, 528, 561, 595, 630, 
        666, 703, 741, 780, 820, 
        861, 903, 946, 990, 1035, 
    };

    for (int i = 0; i < MAX_SIZE;i++)
    {
        if(sizes[i] >= total)
        {
            return i + 1;
        }
    }
    return MAX_SIZE;
}

int computeMethod(int cntA, int cntB, int size, int i = 0)
{
    if(i == size)
    {
        return isAvailable(cntA, cntB, size);
    }
    int total = 0;
    if(cntA != 0)
    {
        tower[0][i] = 0;
        total += computeMethod(cntA - 1, cntB, size, i + 1);
    }
    if(cntB != 0)
    {
        tower[0][i] = 1;
        total += computeMethod(cntA, cntB - 1, size, i + 1);
    }
    return total;
}

bool isAvailable(int cntA, int cntB, int size)
{
    for (int i = 1; i < size;i++)
    {
        for (int j = 0; j < size - i;j++)
        {
            if(tower[i-1][j] ^ tower[i-1][j+1])
            {
                if(cntB == 0)
                    return false;
                else
                {
                    cntB--;
                    tower[i][j] = 1;
                }
            }
            else
            {
                if(cntA == 0)
                {
                    return false;
                }
                else
                {
                    cntA--;
                    tower[i][j] = 0;
                }
            }
        }
    }
    return true;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int size = towerSize(a + b);
    cout << computeMethod(a, b, size);
    return 0;
}