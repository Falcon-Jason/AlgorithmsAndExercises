#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <math.h>
using namespace std;

set<int> map[24];
int mapSize;
int nLines;

void connect(int a, int b)
{
    map[a].insert(b);
    map[b].insert(a);
}

void initMap()
{
    cin >> mapSize >> nLines;
    for (int i = 0; i < nLines; i++)
    {
        int m, n;
        cin >> m >> n;
        connect(m, n);
    }
}

bool find(const vector<int> &path, int val)
{
    for (vector<int>::const_iterator i = path.begin() + 2; i < path.end(); i++)
    {
        if (*i == val)
        {
            return true;
        }
    }
    return false;
}

double computeExpection(int begin, int current, int previous, double weight = 1)
{
    if (previous != 0 && current == begin)
    {
        return 1.0;
    }
    if (weight <= 1e-12)
    {
        return mapSize;
    }
    double sum = 0;
    int count = map[current].size() - 1;
    for (set<int>::iterator i = map[current].begin(); i != map[current].end(); i++)
    {
        if (*i != previous)
        {
            double currentException = computeExpection(begin, *i, current, weight / count);
            sum += currentException;
        }
    }
    double expection = (previous == 0) ? (sum / (count + 1)) : ((sum / count) + 1);

    return expection;
}

int main()
{
    initMap();
 
    for (int i = 1; i <= mapSize; i++)
    {
        double expection = computeExpection(i, i, 0);
        cout << fixed << setprecision(12) << (expection == -1 ? nLines : expection) << endl;
    }
}

// failed