#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int size;
    cin >> size;
    int *values = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> values[i];
    }

    int *minimum = new int[size];
    int *maximum = new int[size];

    maximum[0] = values[0];
    for (int i = 1; i < size; i++)
    {
        maximum[i] = max(maximum[i - 1], values[i]);
    }

    minimum[size - 1] = values[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        minimum[i] = min(minimum[i + 1], values[i]);
    }

    vector<int> results{};

    for (int i = 0; i < size; i++)
    {
        if(maximum[i] == minimum[i])
        {
            results.push_back(maximum[i]);
        }
    }

    cout << results.size() << endl;
    if(results.size() > 0)
    {
        cout << results[0];    
    }
    
    for (int i = 1; i < results.size(); i++)
    {
        cout << " " << results[i];
    }
    cout << endl;

    delete[] values;
    delete[] minimum;
    delete[] maximum;
}