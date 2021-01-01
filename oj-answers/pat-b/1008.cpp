#include <iostream>
#include <vector>

using namespace std;

int *ls;
int n;

void move_one() {
    int last = ls[n-1];
    for(int i = n-1; i>0; i--)
    {
        ls[i] = ls[i-1];
    }
    ls[0] = last;
}

int main() {
    int m;
    cin >> n >> m;
    ls = new int[n];
    for (int i = 0; i < n;i++)
        cin >> ls[i];

    for (int i = 0; i < m;i++){
        move_one();
    }

    cout << ls[0];
    for (int i = 1; i < n; i++)
        cout << " " << ls[i];

    delete[] ls;
    return 0;
}