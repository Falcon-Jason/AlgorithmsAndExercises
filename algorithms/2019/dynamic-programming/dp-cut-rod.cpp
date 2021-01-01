/* 动态规划 求解钢条切割问题 */

#include <iostream>
#include <vector>

#define MAX_SIZE 128
using namespace std;

int dpCutRod(int size, const int *prices, int *dpChoice)
{
    int *dpMaxValue = new int[size + 1];
    int result;
    dpMaxValue[0] = 0;

    for (int i = 1; i <= size; i++)
    {
        dpMaxValue[i] = -1;
        for (int j = 0; j <= i; j++)
        {
            if (dpMaxValue[i] < prices[j] + dpMaxValue[i - j])
            {
                dpMaxValue[i] = prices[j] + dpMaxValue[i - j];
                dpChoice[i] = j;
            }
        }
    }

    result = dpMaxValue[size];
    delete[] dpMaxValue;
    return result;
}

vector<int> &getSolution(int size, int *dpChoice)
{
    vector<int> *solution = new vector<int>{};

    while (size > 0)
    {
        solution->push_back(dpChoice[size]);
        size -= dpChoice[size];
    }

    return *solution;
}

int main()
{
    int size;
    cin >> size;
    int *prices = new int[size + 1];
    int *dpChoice = new int[size + 1];
    prices[0] = 0;
    for (int i = 1; i <= size; i++)
    {
        cin >> prices[i];
    }

    int maxValue = dpCutRod(size, prices, dpChoice);
    vector<int> &solution = getSolution(size, dpChoice);

    cout << maxValue << endl;
    for (auto i = solution.begin(); i < solution.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    delete[] prices;
    delete[] dpChoice;
    delete &solution;

    return 0;
}
