#include <iostream>

#define MAXN 120

int triangle[MAXN][MAXN] = {{0}};
int triangleSize;

using namespace std;
void readTriangle() {
    cin >> triangleSize;
    for (int i = 0; i < triangleSize; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }
}

int dpTriangle() {
    for (int i = triangleSize - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}

int main() {
    readTriangle();
    cout << dpTriangle() << endl;
}

// Status: Accepted
// Submit: 5118423