#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

bool read_vals(int split, vector<int> &vals)
{
    vals.clear();
    int pos = 0;
    string s;
    if (!(cin >> s))
    {
        return false;
    }
    while ((pos = s.find(split)) != -1)
    {
        vals.push_back(atoi(s.substr(0, pos).c_str()));
        s = s.substr(pos + 1, s.size());
    }
    vals.push_back(atoi(s.c_str()));
    return true;
}

int main()
{
    vector<int> vals{};
    while (read_vals(',', vals))
    {
        sort(vals.begin(), vals.end(), [](int a, int b) { return a <= b; });
        int size = vals.size();
        cout << ((vals[(size - 1) >> 1] + vals[(size) >> 1]) >> 1) << endl;
    }
    return 0;
}