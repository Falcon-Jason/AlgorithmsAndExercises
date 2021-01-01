#include <iostream>
#include <sstream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

void flip(vector<int> &array, int bottom);
void flipSort(vector<int> &array);
void readArray(istream &in, vector<int> &arr);
void printList(vector<int> ls);
int indexOf(vector<int> ls, int val);

int main()
{
    string line{};
    vector<int> lineVal{};
    while(getline(cin,line))
    {
        cout << line << endl;
        istringstream lineIss{line};
        readArray(lineIss, lineVal);
        flipSort(lineVal);
    }
    
    return 0;
}

void flipSort(vector<int> &array)
{
    vector<int> sorted{array};
    sort(sorted.rbegin(), sorted.rend() - 1);
    int len = array.size();

    for (int i = 1; i<len; i++)
    {
        int position = indexOf(array,sorted[i]);
        if(position != i)
        {
            if(position != len - 1)
            {
                flip(array, position);
            }
            flip(array, i);
        }
    }
    cout << 0 << endl;
}

void flip(vector<int> &array, int bottom)
{
    cout << bottom << " ";
    int top = array.size() - 1;
    while(top > bottom)
    {
        swap(array[top--], array[bottom++]);
    }
}

void printList(vector<int> ls)
{
    for (auto i = ls.begin(); i != ls.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

int indexOf(vector<int> ls, int val)
{
    for (int i = 0; i < ls.size();i++)
    {
        if(ls[i] == val)
        {
            return i;
        }
    }
    return -1;
}

void readArray(istream &in, vector<int> &arr)
{
    deque<int> d{};

    int val;
    while(in >> val)
    {
        d.push_front(val);
    }

    arr.clear();
    arr.push_back(0);
    for (auto i = d.begin(); i != d.end();i++)
    {
        arr.push_back(*i);
    }
}

// Accepted: https://vjudge.net/solution/18192404