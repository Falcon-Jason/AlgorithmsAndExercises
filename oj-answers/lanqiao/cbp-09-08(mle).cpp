#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#define MAXN 110000
using namespace std;

map<int, vector<int> *> records; //全部点赞记录
int likesLimit;                  //赞数要求
int timeLimit;                   //时间要求

bool isHot(const vector<int> record);

int main()
{
    int n;
    cin >> n >> timeLimit >> likesLimit;
    for (int i = 0; i < n; i++)
    {
        int ts, id;
        cin >> ts >> id;
        if (records.find(id) == records.end())
        {
            records.insert(pair<int, vector<int> *>(id, new vector<int>{}));
        }
        records.at(id)->push_back(ts);
    }
    for (auto i = records.begin(); i != records.end(); ++i)
    {
        if(isHot(*i->second))
            cout << i->first << endl;
        delete i->second;
    }
    return 0;
}

bool isHot(const vector<int> record)
{
    int *diff = new int[MAXN]{};
    int sum;

    for (auto i = record.begin(); i != record.end();++i)
    {
        diff[*i]++;
        if(*i + timeLimit < MAXN)
            diff[*i + timeLimit]--;
    }
    sum = diff[0];
    for (int i = 1; i < MAXN;i++)
    {
        sum += diff[i];
        if(sum >= likesLimit)
            return true;
    }
    return false;
}

void debug_PrintRecords()
{
    for (auto i = records.begin(); i != records.end(); ++i)
    {
        cout << i->first << ":";
        for (auto j = i->second->begin(); j != i->second->end(); j++)
        {
            cout << " " << *j;
        }
        cout << endl;
    }
}