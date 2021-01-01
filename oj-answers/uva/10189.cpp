#include <iostream>
#include <cstring>

#define ismine(x, y) (field[x][y] == -1)
using namespace std;

const int MAX_SIZE = 110;

int field[MAX_SIZE][MAX_SIZE];
int size_m;
int size_n;

int getch();
void readfield(int, int);
void calcfield();
void printfield();

int getch()
{
    int c;
    while (isspace(c = getchar()))
        ;
    return c;
}

void readfield(int m, int n)
{
    memset(field, 0, sizeof(field));
    size_m = m;
    size_n = n;
    for (int i = 1; i <= size_m; i++)
    {
        for (int j = 1; j <= size_n; j++)
        {
            int n = getch();
            field[i][j] = n == '*' ? -1 : 0;
            // cout << field[i][j];
        }
        // cout << endl;
    }
}

void calcfield()
{

    for (int i = 1; i <= size_m; i++)
    {
        for (int j = 1; j <= size_n; j++)
        {
            if (field[i][j] != -1)
            {
                field[i][j] = ismine(i - 1, j - 1) +
                              ismine(i - 1, j) +
                              ismine(i - 1, j + 1) +
                              ismine(i, j - 1) +
                              ismine(i, j + 1) +
                              ismine(i + 1, j - 1) +
                              ismine(i + 1, j) +
                              ismine(i + 1, j + 1);
            }
        }
    }
}

void printfield()
{
    for (int i = 1; i <= size_m; i++)
    {
        for (int j = 1; j <= size_n; j++)
        {
            if (field[i][j] == -1)
                cout << '*';
            else
                cout << field[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int m, n;
    int i = 0;
    cin >> m >> n;
    while (m != 0 && n != 0)
    {
        readfield(m, n);
        calcfield();
        if(i!=0){
            cout << endl;
        }
        cout << "Field #" << ++i << ":" << endl;
        printfield();
        cin >> m >> n;
    }
    return 0;
}

// Accepted: https://vjudge.net/solution/17961886/