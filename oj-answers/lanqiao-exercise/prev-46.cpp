#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

#define X 0
#define L 1
#define O 2

#define TAIL 0
#define UNCERTAIN 2
#define M_WIN 1
#define K_WIN -1
using namespace std;


int winner(int winner1, int winner2, int curplayer)
{
    // cout << winner1 << "," << winner2 << "," << curplayer << ",";
    int res = UNCERTAIN;
    if(winner1 == UNCERTAIN)
        res = winner2;
    else if(winner1 == curplayer || winner2 == curplayer)
        res = curplayer;
    else if(winner1 == winner2)
        res = winner1;
    else
        res = TAIL;
    // cout << res << endl;
    return res;
}

std::vector<int> board;



bool towin()
{
    static int pre_auto[][3] = {
        {1, 1, 1},
        {0, 0, 3},
        {0, 2, 0},
    };
    static int mid_auto[][3] = {
        {0, 2, 0},
        {1, 1, 3},
        {0, 0, 0},
    };
    static int pos_auto[][3] = {
        {0, 0, 3},
        {1, 1, 1},
        {0, 2, 0},
    };

    int pre_state = 0;
    int mid_state = 0;
    int pos_state = 0;
    for (vector<int>::iterator i = board.begin(); i != board.end(); i++)
    {
        pre_state = pre_auto[*i][pre_state];
        mid_state = mid_auto[*i][mid_state];
        pos_state = pos_auto[*i][pos_state];
        if(pre_state == 3 || mid_state == 3 || pos_state == 3)
            return true;
    }
    return false;
}

int dfs(int curplayer)
{
    // int crp = curplayer;
    // cout << curplayer << " ";
    // printboard();
    if(towin())
    {
        // cout << "TOWIN: " << -curplayer << endl;
        return curplayer;
    }
    int possibleWinner = UNCERTAIN;
    for (vector<int>::iterator i = board.begin(); i != board.end(); i++)
    {
        if(*i == X)
        {
            *i = L;
            possibleWinner = winner(possibleWinner, dfs(-curplayer), curplayer);
            if(possibleWinner == curplayer)
                return curplayer;
            *i = O;
            possibleWinner = winner(possibleWinner, dfs(-curplayer), curplayer);
            if(possibleWinner == curplayer)
                return curplayer;
            *i = X;
        }
    }
    return possibleWinner;
}

void readboard(istream &in)
{
    board.clear();
    for (int ch = in.get(); ch != EOF;ch = in.get())
    {
        if(ch == 'L')
            board.push_back(L);
        else if(ch == 'O')
            board.push_back(O);
        else
            board.push_back(X);
    }
}

int main()
{
    string line;
    int n;
    getline(cin, line);
    n = atoi(line.c_str());
    for (int i = 0; i < n;i++)
        {
            getline(cin, line);
            istringstream iss(line);
            readboard(iss);
            cout << -dfs(-1) << endl;
        }
}

void printboard()
{
    for (vector<int>::iterator i = board.begin(); i != board.end();i++)
    {
        switch(*i)
        {
            case L:
                cout << "L";
                break;
            case O:
                cout << "O";
                break;
            default:
                cout << "X";
        }
    }
    cout << endl;
}