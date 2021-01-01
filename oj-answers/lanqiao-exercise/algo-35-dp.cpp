#include <iostream>
#define MAXN 32

using namespace std;

int cases[MAXN][MAXN] = {0};
int cycleSize = 0;
int stepCount = 0;
inline int Next(int k) {
    return k == cycleSize ? 1 : k + 1;
}

inline int Prev(int k) {
    return k == 1 ? cycleSize : k - 1;
}

int CalcCases() {
    cases[0][1] = 1;
    for (int i = 1; i <= stepCount; i++) {
        for (int j = 1; j <= cycleSize; j++) {
            cases[i][j] = cases[i - 1][Prev(j)] + cases[i - 1][Next(j)];
        }
    }
    return cases[stepCount][1];
}

int main() {
    cin >> cycleSize >> stepCount;
    cout << CalcCases() << endl;
    return 0;
}

// Status: Accepted
// Submit: 5114340