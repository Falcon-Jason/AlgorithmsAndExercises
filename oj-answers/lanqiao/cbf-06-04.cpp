#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> encodeds{};

void init_encoded(const string &text)
{
    int end = text.size() - 8 + 1;
    for (int i = 0; i < end; i++)
    {
        string eightbit = text.substr(i, 8);
        sort(eightbit.begin(), eightbit.end());
        encodeds.push_back(eightbit);
    }
}

int main()
{
    string text;
    string key;
    cin >> text;
    init_encoded(text);
    int key_cnt;
    int matched_cnt = 0;
    cin >> key_cnt;
    for (int i = 0; i < key_cnt;i++)
    {
        cin >> key;
        sort(key.begin(), key.end());
        for (auto itor = encodeds.begin(); itor != encodeds.end(); itor++)
        {
            if(key == *itor)
            {
                matched_cnt++;
            }
        }
    }
    cout << matched_cnt << endl;
}