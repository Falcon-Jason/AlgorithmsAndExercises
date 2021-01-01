#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define MAX_SIZE 16
using namespace std;
bool isInserted(const char *s1, const char *s2, const char *s3)
{
    if (strlen(s3) != strlen(s1) + strlen(s2))
    {
        return false;
    }
    if (strlen(s3) == 0)
    {
        return (!strcmp(s1, s3)) || (!strcmp(s2, s3));
    }

    if (strlen(s1) != 0 && *s1 == *s3 && isInserted(s1 + 1, s2, s3 + 1))
    {
        return true;
    }
    if (strlen(s2) != 0 && *s2 == *s3 && isInserted(s1, s2 + 1, s3 + 1))
    {
        return true;
    }
    return false;
}

vector<string> &strSplit(string s, int c, vector<string> &splited)
{
    splited.clear();
    int pos = 0;
    while ((pos = s.find(c)) != -1)
    {
        splited.push_back(s.substr(0, pos));
        s = s.substr(pos + 1, s.size());
    }
    splited.push_back(s);
    return splited;
}

int main()
{
    vector<string> sl{};
    string line{};
    while (cin >> line)
    {
        strSplit(line, ',', sl);
        cout << boolalpha << isInserted(sl[0].c_str(), sl[1].c_str(), sl[2].c_str()) << endl;
    }
    return 0;
}
