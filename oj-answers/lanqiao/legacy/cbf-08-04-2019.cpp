#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

#define MAX_SIZE 110000
using namespace std;

list<int> map[MAX_SIZE];
int mapSize;

void printVector(vector<int> &v)
{
    for (vector<int>::iterator i = v.begin(); i < v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}
bool isSearched(const vector<int> &status, int current)
{
    for (vector<int>::const_iterator i = status.begin(); i < status.end(); i++)
    {
        if (*i == current)
            return true;
    }
    return false;
}

bool search(vector<int> &status)
{
    // printVector(status);
    for (list<int>::iterator i = map[*(status.end() - 1)].begin(); i != map[*(status.end() - 1)].end(); i++)
    {
        if (status.size() > 2 && status[0] == *i)
        {
            // cout << "!!!";
            // printVector(status);
            return true;
        }

        if (!isSearched(status, *i))
        {
            status.push_back(*i);
            if (search(status))
                return true;
        }
    }
    status.pop_back();
    return false;
}

void connect(int i, int j)
{
    map[i].push_back(j);
    map[j].push_back(i);
}

void readMap()
{
    int m, n;
    cin >> mapSize;
    for (int i = 0; i < mapSize; i++)
    {
        cin >> m >> n;
        connect(m, n);
    }
}

void printMap()
{
    for (int i = 1; i <= mapSize; i++)
    {
        cout << i << ":";
        for (list<int>::iterator j = map[i].begin(); j != map[i].end(); j++)
        {
            cout << " " << *j;
        }
        cout << endl;
    }
}

int main()
{
    vector<int> itor;

    readMap();

    for (int i = 1; i <= mapSize; i++)
    {
        itor.clear();
        itor.push_back(i);
        if (search(itor))
        {
            break;
        }
    }

    sort(itor.begin(), itor.end());
    for (vector<int>::iterator i = itor.begin(); i < itor.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

// Accepted: http://lx.lanqiao.cn/detail.page?submitid=3688618