#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
vector<int> &str_split(string s, int c, vector<int> &splited)
{
    splited.clear();
    int pos = 0;
    while ((pos = s.find(c)) != -1)
    {
        int i = atoi(s.substr(0, pos).c_str());
        if (i > 0)
            splited.push_back(i);
        // cout << s.substr(0, pos) << endl;
        s = s.substr(pos + 1, s.size());
    }
    int i_ = atoi(s.c_str());
    if (i_ > 0)
        splited.push_back(i_);
    if (splited.size() != 0)
        sort(splited.begin(), splited.end(), [](int a, int b) { return a <= b; });
    return splited;
}

int minMissed(vector<int> sl)
{
    if (sl.size() == 0)
    {
        return 1;
    }
    for (int i = 1; i < sl.size(); i++)
    {
        if (sl[i] != sl[i - 1] + 1)
        {
            return sl[i - 1] + 1;
        }
    }
    return sl[sl.size() - 1] + 1;
}

int main()
{
    vector<int> sl{};
    string l{};
    cin >> l;
    str_split(l, ',', sl);
    cout << minMissed(sl) << endl;
    return 0;
}