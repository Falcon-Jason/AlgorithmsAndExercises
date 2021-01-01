/* 动态规划 求解资源分配问题 */
#include <iostream>

#define MAX_DEPARTMENTS 64
#define MAX_RESOURCES 128

using namespace std;

int nDepartment;
int nResource;
int interests[MAX_DEPARTMENTS][MAX_RESOURCES];
int dpInterest[MAX_DEPARTMENTS][MAX_RESOURCES];
int dpChoice[MAX_DEPARTMENTS][MAX_RESOURCES];

int dpResourceSharing()
{
    for (int i = 0; i < nResource; i++)
    {
        dpInterest[0][i] = interests[0][i];
        dpChoice[0][i] = i;
    }
    for (int i = 1; i < nDepartment; i++)
    {
        dpInterest[i][0] = 0;
        for (int j = 0; j <= nResource; j++)
        {
            dpInterest[i][j] = 0;
            for (int k = 0; k <= j; k++)
            {
                if (dpInterest[i - 1][j - k] + interests[i][k] > dpInterest[i][j])
                {
                    dpInterest[i][j] = dpInterest[i - 1][j - k] + interests[i][k];
                    dpChoice[i][j] = k;
                }
            }
        }
    }
    return dpInterest[nDepartment - 1][nResource];
}

int *getSolution(int *solution)
{
    int r = nResource;
    for (int i = nDepartment - 1; i >= 0; i--)
    {
        solution[i] = dpChoice[i][r];
        r -= dpChoice[i][r];
    }
    return solution;
}

int main()
{
    cin >> nDepartment >> nResource;
    int *result = new int[nDepartment];

    for (int i = 0; i < nDepartment; i++)
    {
        interests[i][0] = 0;
        for (int j = 1; j <= nResource; j++)
        {
            cin >> interests[i][j];
        }
    }
    cout << dpResourceSharing() << endl;
    getSolution(result);

    for (int i = 0; i < nDepartment; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    delete[] result;
    return 0;
}
