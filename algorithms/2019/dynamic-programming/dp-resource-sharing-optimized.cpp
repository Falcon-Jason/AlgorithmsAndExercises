/* 动态规划 求解资源分配问题 
 * 改进代码 删除了外部变量
 */
template <class T>
struct Matrix
{
    T *value;
    int size_x;
    int size_y;

    Matrix(int x, int y)
    {
        size_x = x;
        size_y = y;
        value = new T[size_x * size_y];
    }

    ~Matrix()
    {
        delete[] value;
    }

    T *operator[](int x)
    {
        return &value[x * size_y];
    }
};

#include <iostream>
#define MAX_DEPARTMENTS 64
#define MAX_RESOURCES 128

using namespace std;

int dpResourceSharing(int nDepartment, int nResource, Matrix<int> &interests, Matrix<int> &dpChoice)
{
    Matrix<int> dpInterest{nDepartment, nResource + 1};
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

int *getSolution(int nDepartment, int nResource, Matrix<int> &dpChoice)
{
    int *solution = new int[nDepartment];
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
    int nDepartment, nResource;
    cin >> nDepartment >> nResource;
    Matrix<int> interests{nDepartment, nResource + 1};
    Matrix<int> dpChoice{nDepartment, nResource + 1};

    for (int i = 0; i < nDepartment; i++)
    {
        interests[i][0] = 0;
        for (int j = 1; j <= nResource; j++)
        {
            cin >> interests[i][j];
        }
    }
    int maxInterest = dpResourceSharing(nDepartment, nResource, interests, dpChoice);
    int *result = getSolution(nDepartment, nResource, dpChoice);

    cout << maxInterest << endl;
    for (int i = 0; i < nDepartment; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] result;
    return 0;
}
