#include <iostream>

constexpr int SIZE = 110;
constexpr int MOD = 1000000007;
using llong = long long;
using namespace std;

int width;
int height;
int connection[SIZE][SIZE] = {{0}};
llong dpfunc[SIZE][SIZE] = {{0}};

void readConnection() {
    cin >> height >> width;
    char ch;
    for (int i = height; i > 0; i--) {
        connection[i][0] = 0;
        for (int j = 1; j <= width; j++) {
            cin >> ch;
            connection[i][j] = connection[i][j - 1] + (ch == 'X');
        }
    }
}

void printConnection() {
    for (int i = 1; i <= height; i++) {
        for (int j = 0; j <= width; j++) {
            cout << connection[i][j];
        }
        cout << endl;
    }
}

bool connected(int height, int low, int high) {
    return connection[height][high] - connection[height][low - 1] == 0;
}

void initDpfunc() {
    for (int i = 1; i <= width; i++) {
        for (int j = width; j >= i; j--) {
            dpfunc[i][j] = connected(1, i, j);
        }
    }
}

llong dpPaper() {
    llong count = 1;
    for (int h = 1; h <= height; h++) {
        for (int i = 1; i <= width; i++) {
            for (int j = width; j >= i; j--) {
                if (connected(h, i, j)) {
                    count += dpfunc[i][j];
                    count %= MOD;
                    dpfunc[i][j] += (dpfunc[i][j + 1] + dpfunc[i - 1][j] - dpfunc[i - 1][j + 1]) % MOD;
                } else {
                    dpfunc[i][j] = 0;
                }
            }
        }
    }
    return count;
}

int main() {
    readConnection();
    initDpfunc();
    cout << dpPaper() << endl;
}