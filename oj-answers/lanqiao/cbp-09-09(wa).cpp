#include <cstring>
#include <iostream>
#include <algorithm>

#define MAXN 1100
using namespace std;

int picture[MAXN][MAXN];
int pictureSize;

int readPicture();
void printPicture();
int scanUnion();
void submergeOnce();

int main()
{
    readPicture();
    scanUnion();

    submergeOnce();

    cout << scanUnion() << endl;
    return 0;
}

int readPicture()
{
    int landId = 0;
    memset(picture, 0, sizeof(picture));
    cin >> pictureSize;
    cin.get();
    for (int i = 1; i <= pictureSize; i++)
    {
        for (int j = 1; j <= pictureSize; j++)
        {
            picture[i][j] = (cin.get() == '#' ? ++landId : 0);
        }
        cin.get();
    }
    return landId;
}

void printPicture()
{
    for (int i = 0; i <= pictureSize + 1; i++)
    {
        for (int j = 0; j <= pictureSize + 1; j++)
        {
            cout << picture[i][j] << ' ';
        }
        cout << endl;
    }
}

int scanUnionOnce()
{
    for (int i = 1; i <= pictureSize; i++)
    {
        for (int j = 1; j <= pictureSize; j++)
        {
            if (picture[i][j] > 0)
            {
                if (picture[i][j - 1] > 0)
                    picture[i][j - 1] = picture[i][j] = min(picture[i][j - 1], picture[i][j]);
                if (picture[i - 1][j] > 0)
                    picture[i - 1][j] = picture[i][j] = min(picture[i - 1][j], picture[i][j]);
                if (picture[i][j + 1] > 0)
                    picture[i][j + 1] = picture[i][j] = min(picture[i][j + 1], picture[i][j]);
                if (picture[i + 1][j] > 0)
                    picture[i + 1][j] = picture[i][j] = min(picture[i + 1][j], picture[i][j]);
            }
        }
    }
    int unions = 0;
    int maxId = 0;
    for (int i = 1; i <= pictureSize; i++)
    {
        for (int j = 1; j <= pictureSize; j++)
        {
            if (picture[i][j] > maxId)
            {
                maxId = picture[i][j];
                unions++;
            }
        }
    }
    return unions;
}

int scanUnion()
{
    int islands = 0;
    for (int i = scanUnionOnce(); i != islands; i = scanUnionOnce())
    {
        islands = i;
    }
    return islands;
}

void submergeOnce()
{
    for (int i = 1; i <= pictureSize; i++)
    {
        for (int j = 1; j <= pictureSize; j++)
        {
            if (picture[i][j] && (!picture[i][j - 1] || !picture[i - 1][j] || !picture[i][j + 1] || !picture[i + 1][j]))
            {
                picture[i][j] = -1;
            }
        }
    }
    for (int i = 1; i <= pictureSize; i++)
    {
        for (int j = 1; j <= pictureSize; j++)
        {
            if(picture[i][j] == -1)
                picture[i][j] = 0;
        }
    }
}