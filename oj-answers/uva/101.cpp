#include <cstring>
#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <vector>
using namespace std;

#define MAX_SIZE 25

int totalSize;
int positions[MAX_SIZE];
vector<int> piles[MAX_SIZE];

void moveOnto(int, int);
void moveOver(int, int);
void pileOnto(int, int);
void pileOver(int, int);

void place(int block, int position);
void initialize(int);
void doCommand(const string &);
void printPile();

int main()
{
    int size;
    cin >> size;
    initialize(size);
    string str;
    while (getline(cin, str) && str != "quit")
    {
        doCommand(str);
    }
    printPile();
    return 0;
}

void initialize(int initialSize)
{
    totalSize = initialSize;

    for (int i = 0; i < totalSize; i++)
    {
        positions[i] = i;
        piles[i].clear();
        piles[i].push_back(i);
    }
}

void printPile()
{
    for (int i = 0; i < totalSize; i++)
    {
        cout << i << ":";
        for (int j = 0; j < piles[i].size(); j++)
        {
            cout << " " << piles[i][j];
        }
        cout << endl;
    }
}

void doCommand(const string &str)
{
    istringstream iss{str};
    string arg1, arg3;
    int arg2, arg4;
    iss >> arg1 >> arg2 >> arg3 >> arg4;

    if (arg1 == "move" && arg3 == "onto")
        moveOnto(arg2, arg4);
    else if (arg1 == "move" && arg3 == "over")
        moveOver(arg2, arg4);
    else if (arg1 == "pile" && arg3 == "onto")
        pileOnto(arg2, arg4);
    else if (arg1 == "pile" && arg3 == "over")
        pileOver(arg2, arg4);
}

void place(int block, int position)
{
    piles[position].push_back(block);
    positions[block] = position;
}

void moveOnto(int blockA, int blockB)
{
    int positionA = positions[blockA];
    int positionB = positions[blockB];

    if (positionA == positionB)
    {
        return;
    }

    int topBlock;
    while ((topBlock = *(piles[positionA].rbegin())) != blockA)
    {
        place(topBlock, topBlock);
        piles[positionA].pop_back();
    }
    while ((topBlock = *(piles[positionB].rbegin())) != blockB)
    {
        place(topBlock, topBlock);
        piles[positionB].pop_back();
    }
    place(blockA, positionB);
    piles[positionA].pop_back();
}
void moveOver(int blockA, int blockB)
{
    int positionA = positions[blockA];
    int positionB = positions[blockB];

    if (positionA == positionB)
    {
        return;
    }

    int topBlock;
    while ((topBlock = *(piles[positionA].rbegin())) != blockA)
    {
        place(topBlock, topBlock);
        piles[positionA].pop_back();
    }
    place(blockA, positionB);
    piles[positionA].pop_back();
}

void pileOnto(int blockA, int blockB)
{
    int positionA = positions[blockA];
    int positionB = positions[blockB];

    if (positionA == positionB)
    {
        return;
    }

    stack<int> s;
    int topBlock;
    while((topBlock = *(piles[positionA].rbegin())) != blockA)
    {
        s.push(topBlock);
        piles[positionA].pop_back();
    }
    piles[positionA].pop_back();
    s.push(blockA);

    while ((topBlock = *(piles[positionB].rbegin())) != blockB)
    {
        place(topBlock, topBlock);
        piles[positionB].pop_back();
    }

    while(!s.empty())
    {
        place(s.top(), positionB);
        s.pop();
    }
}
void pileOver(int blockA, int blockB)
{
    int positionA = positions[blockA];
    int positionB = positions[blockB];

    if (positionA == positionB)
    {
        return;
    }

    stack<int> s;
    int topBlock;
    while((topBlock = *(piles[positionA].rbegin())) != blockA)
    {
        s.push(topBlock);
        piles[positionA].pop_back();
    }
    piles[positionA].pop_back();
    s.push(blockA);

    while(!s.empty())
    {
        place(s.top(), positionB);
        s.pop();
    }
}

// Accepted: uva submission 22842840