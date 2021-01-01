#include <iostream>
#include <string>
using namespace std;

string order;
int minMovement;
int count[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int movement[3][3];

bool readCount()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (!(cin >> count[i][j]))
            {
                return false;
            }
        }
    }
    return true;
}

void calcMovement()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            movement[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                if (k != i)
                {
                    movement[i][j] += count[k][j];
                }
            }
        }
    }
}

void calcOrder()
{
    minMovement = movement[0][0] + movement[1][2] + movement[2][1];
    order = "BCG";

    if (minMovement > movement[0][0] + movement[1][1] + movement[2][2])
    {
        minMovement = movement[0][0] + movement[1][1] + movement[2][2];
        order = "BGC";
    }
    if (minMovement > movement[0][2] + movement[1][0] + movement[2][1])
    {
        minMovement = movement[0][2] + movement[1][0] + movement[2][1];
        order = "CBG";
    }
    if (minMovement > movement[0][2] + movement[1][1] + movement[2][0])
    {
        minMovement = movement[0][2] + movement[1][1] + movement[2][0];
        order = "CGB";
    }
    if (minMovement > movement[0][1] + movement[1][0] + movement[2][2])
    {
        minMovement = movement[0][1] + movement[1][0] + movement[2][2];
        order = "GBC";
    }
    if (minMovement > movement[0][1] + movement[1][2] + movement[2][0])
    {
        minMovement = movement[0][1] + movement[1][2] + movement[2][0];
        order = "GCB";
    }
}

int main()
{
    while (readCount())
    {
        calcMovement();
        calcOrder();
        cout << order << " " << minMovement << endl;
    }
    return 0;
}

// Accepted: uva submission 22842802