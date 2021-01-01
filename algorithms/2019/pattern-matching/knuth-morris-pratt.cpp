#include <iostream>
#include <string>
#include <vector>

using namespace std;

int *computePrefix(const string &pattern)
{
    int *prefix = new int[pattern.size()]{0};
    int k = 0;

    for (int i = 1; i < pattern.size(); i++)
    {
        while (k > 0 && pattern[k] != pattern[i])
        {
            k = prefix[k];
        }
        if (pattern[k] == pattern[i])
        {
            k++;
        }
        prefix[i] = k;
    }

    return prefix;
}

vector<int> match(const string &text, const string &pattern)
{
    int tsize = text.size();
    int psize = pattern.size();
    vector<int> matched{};

    int *prefix = computePrefix(pattern);
    
    int prefix_length = 0;
    for (int i = 0; i < tsize; i++)
    {
        while (prefix_length > 0 && pattern[prefix_length] != text[i])
        {
            prefix_length = prefix[prefix_length - 1];
        }
        if (pattern[prefix_length] == text[i])
        {
            prefix_length++;
        }
        if (prefix_length == psize)
        {
            matched.push_back(i - psize + 1);
        }
    }
    delete[] prefix;
    return matched;
}

int main()
{
    string text, pattern;
    getline(cin, pattern);
    while (getline(cin, text))
    {
        auto m = match(text, pattern);
        cout << text << endl;
        auto iter = m.begin();
        for (int i = 0; i < text.size(); i++)
        {
            if (iter != m.end() && i == *iter)
            {
                cout << '^';
                ++iter;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}