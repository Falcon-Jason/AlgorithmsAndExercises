#include <iostream>
#define MAXN 32

using namespace std;

int shortestPath[MAXN];
int oppositePos = 0;
int cycleSize = 0;

inline int Next(int k) {
    return k == cycleSize ? 1 : k + 1;
}

inline int Prev(int k) {
    return k == 1 ? cycleSize : k - 1;
}

void CalcShortestPath() {
    if (cycleSize % 2 == 0) {
        oppositePos = cycleSize / 2 + 1;
    }
    shortestPath[0] = shortestPath[1] = 0;
    for (int i = 2, j = cycleSize, s = 1; i <= j; i++, j--, s++) {
        shortestPath[i] = shortestPath[j] = s;
    }
}

int Search(int currentPos, int stepRemain) {
    if (shortestPath[currentPos] > stepRemain) {
        return 0;
    }

    if (shortestPath[currentPos] == stepRemain) {
        return currentPos == oppositePos ? 2 : 1;
    }

    return Search(Next(currentPos), stepRemain - 1) +
           Search(Prev(currentPos), stepRemain - 1);
}

int main() {
    int stepCount;
    cin >> cycleSize >> stepCount;
    CalcShortestPath();
    cout << Search(1, stepCount) << endl;
    return 0;
}

// Status: Partial Accepted(1 Case TLE)
// Submit: 5104652