#include <iostream>
#include <list>
#define MAX_SIZE 110000
#define MOD 10007
#define LIMIT 0x100000

using namespace std;

int soildersCount;
list<int> subSoilders[MAX_SIZE];
int superiorSoilder[MAX_SIZE];
int choices[MAX_SIZE][2];

int programmingChoices();

int main()
{
    cin >> soildersCount;

    superiorSoilder[1] = 0;
    choices[1][0] = choices[1][1] = 1;
    for (int i = 2; i <= soildersCount; i++)
    {
        cin >> superiorSoilder[i];
        subSoilders[superiorSoilder[i]].push_back(i);
        choices[i][0] = choices[i][1] = 1;
    }

    cout << programmingChoices();
    return 0;
}

int programmingChoices()
{
    for (int i = soildersCount; i > 0; --i)
    {
        if(!subSoilders[i].empty())
        {
            for (auto j = subSoilders[i].begin(); j != subSoilders[i].end(); j++)
            {
                choices[i][1] *= choices[*j][0];
                choices[i][0] *= choices[*j][0] + choices[*j][1];

                if(choices[i][1] > LIMIT)
                    choices[i][1] %= MOD;
                if (choices[i][0] > LIMIT)
                    choices[i][0] %= MOD;
            }
        }
    }
    return choices[1][0] + choices[1][1] - 1;
}