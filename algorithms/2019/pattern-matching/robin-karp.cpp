#include <iostream>
#include <string>
#include <vector>

using namespace std;

int modPow(int base, int index, int mod)
{
    int pow = 1;
    for (int i = 0; i < index; i++)
    {
        pow *= base;
        pow %= mod;
    }
    return pow;
}

vector<int> match(const string &text, const string &pattern)
{
    const int BASE = 16;
    const int MOD = 1e9 + 7;

    vector<int> ans{};

    int textSize = text.size();
    int patternSize = pattern.size();
    int highestDigit = modPow(BASE, patternSize - 1, MOD);

    vector<int> textHashCodes{0};
    int patternHashCode = 0;

    for (int i = 0; i < patternSize; i++)
    {
        patternHashCode = (patternHashCode * BASE + (pattern[i])) % MOD;
        textHashCodes[0] = (textHashCodes[0] * BASE + (text[i])) % MOD;
    }

    for (int i = 1; i < textSize - patternSize + 1; i++)
    {
        int tcode = (((textHashCodes.back() - (highestDigit * (text[i - 1]))) * BASE % MOD) + 
                       text[i + patternSize - 1]) % MOD;

        textHashCodes.push_back(tcode);
    }
    for (int i = 0; i < textHashCodes.size(); i++)
    {
        if (textHashCodes[i] == patternHashCode && text.substr(i,patternSize) == pattern)
        {
            ans.push_back(i);
        }
    }
    return ans;
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
            if (iter!=m.end() && i == *iter)
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