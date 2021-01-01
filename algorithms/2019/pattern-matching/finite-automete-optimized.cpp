#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Transition
{
  private:
    vector<int *> data;
    vector<int> alphabet;
    string pattern;
    int *prefix;

    void initTransition()
    {
        int size = pattern.size();
        // init transition[i,0]
        for (int i = 0; i < alphabet.size(); i++)
        {
            data[i][0] = pattern[0] == alphabet[i] ? 1 : 0;
        }

        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < alphabet.size(); j++)
            {
                int c = alphabet[j];
                if (pattern[i] != c)
                {
                    data[j][i] = data[j][prefix[i - 1]];
                }
                else
                {
                    data[j][i] = i + 1;
                }
            }
        }
        // init transition[i,size]
        for (int i = 0; i < alphabet.size(); i++)
        {
            data[i][size] = data[i][prefix[size - 1]];
        }
    }

    void initPrefix()
    {
        prefix = new int[pattern.size()]{0};
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
    }

    int letterIndex(int letter)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (alphabet[i] == letter)
                return i;
        }
        return -1;
    }

    bool isSuffixPattern(int begin, int end, char suffix)
    {
        if (begin == 0)
            return true;
        int pbegin = begin - 1;
        int pend = end - 1;
        if (pattern[pbegin] != suffix)
            return false;
        for (pbegin--; pbegin >= 0; pbegin--, pend--)
        {
            if (pattern[pbegin] != pattern[pend])
                return false;
        }
        return true;
    }

  public:
    Transition(const string &pattern)
    {
        int size = pattern.size() + 1;
        for (auto i = pattern.begin(); i < pattern.end(); i++)
        {
            if (letterIndex(*i) == -1)
            {
                alphabet.push_back(*i);
                data.push_back(new int[size]);
            }
        }
        this->pattern = pattern;
        initPrefix();
        initTransition();
    }

    ~Transition()
    {
        for (auto i = data.begin(); i < data.end(); i++)
        {
            delete[](*i);
        }
    }

    int get(char letterInput, int currentPosition)
    {
        int index = letterIndex(letterInput);
        return (index == -1) ? 0 : data[index][currentPosition];
    }

    void print()
    {
        for (int i = 0; i < data.size(); i++)
        {
            cout << (char)alphabet[i] << ": ";
            for (int j = 0; j <= pattern.size(); j++)
            {
                cout << " " << data[i][j];
            }
            cout << endl;
        }
    }
};

vector<int> match(const string &text, const string &pattern)
{
    int tsize = text.size();
    int psize = pattern.size();
    Transition transition{pattern};
    int position = 0;
    vector<int> matched{};

    for (int i = 0; i < tsize; i++)
    {
        // cout << position << " -> ";
        position = transition.get(text[i], position);
        // cout << position << endl;
        if (position == psize)
            matched.push_back(i - psize + 1);
    }
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
