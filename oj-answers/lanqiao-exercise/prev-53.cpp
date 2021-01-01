#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX_SIZE 110
using namespace std;

bool connected[MAX_SIZE][MAX_SIZE];
int arrangement[MAX_SIZE][MAX_SIZE];
int arrangement_size[MAX_SIZE];
int min_nrooms;
int nstudents;

void arrange(int istudent, int nrooms);
bool arrangable(int istudent, int iroom);
void read_connection(int ncommands);
void print_connection();
ostream &operator<<(ostream &out, const vector<int> &v);
int main()
{
    int ncommand;
    memset(connected, 0, sizeof(connected));
    memset(arrangement, 0, sizeof(arrangement));
    memset(arrangement_size, 0, sizeof(arrangement_size));
    cin >> nstudents >> ncommand;
    min_nrooms = nstudents;
    read_connection(ncommand);
    arrange(0, 1);
    cout << min_nrooms << endl;
}

void arrange(int istudent, int nrooms)
{ 
    if (nrooms >= min_nrooms)
    {
        return;
    }

    if(istudent == nstudents)
    {
        min_nrooms = min(min_nrooms, nrooms);
        return;
    }
    for (int i = 0; i < nrooms;i++)
    {
        if(arrangable(istudent, i))
        {
            arrangement[i][arrangement_size[i]++]=istudent;
            arrange(istudent + 1, nrooms);
            arrangement_size[i]--;
        }
    }

    arrangement[nrooms][arrangement_size[nrooms]++] = istudent;
    arrange(istudent + 1, nrooms + 1);
    arrangement_size[nrooms]--;
}

void read_connection(int ncommands)
{
    int m, n;
    for (int i = 0; i < ncommands;i++)
    {
        cin >> m >> n;
        connected[m-1][n-1] = connected[n-1][m-1] = 1;
    }
}

void print_connection()
{
    for (int i = 0; i < nstudents;i++)
    {
        for (int j = 0; j < nstudents;j++)
        {
            cout << connected[i][j];
        }
        cout << endl;
    }
}

bool arrangable(int istudent, int iroom)
{
    for (int i = 0;i < arrangement_size[iroom];i++)
    {
        if(istudent == arrangement[iroom][i] || connected[istudent][arrangement[iroom][i]])
        {
            return false;
        }
    }
    return true;
}
//partily accepted: http://lx.lanqiao.cn/detail.page?submitid=3724044