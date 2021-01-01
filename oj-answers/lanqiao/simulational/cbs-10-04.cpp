#include <algorithm>
#include <iostream>
#include <cstring>
#define MAX_N 256

using namespace std;

int main()
{
    int matrix[MAX_N];
    int n;
    cin >> n;
    memset(matrix, 0, sizeof(matrix));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            matrix[j] += a;
        }
    }

    sort(matrix, matrix + n);

    for (int i = 0; - matrix[i] > matrix[i + 1]; i += 2)
    {
        matrix[i] *= -1;
        matrix[i + 1] *= -1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += matrix[i];
    }
    cout << sum;
    return 0;
}