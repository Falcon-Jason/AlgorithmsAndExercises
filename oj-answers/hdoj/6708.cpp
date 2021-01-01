#include <iostream>

using namespace std;

const char C = 'C';
const char P = 'P';
char window[1 << 10][1 << 10] = {
    {C, C},
    {P, C}};
int windowBuffered = 1;

void CalcWindow(int k) {
    if (k <= windowBuffered) {
        return;
    }

    CalcWindow(k - 1);
    int base = 1 << (k - 1);
    for (int i = 0; i < base; i++) {
        for (int j = 0; j < base; j++) {
            window[i][base + j] = window[i][j];
            window[base + i][j] = ((window[i][j] == C) ? P : C);
            window[base + i][base + j] = window[i][j];
        }
    }
    windowBuffered = k;
}

int main() {
    int times;
    cin >> times;
    for (int i = 0; i < times; i++) {
        int size;
        cin >> size;
        CalcWindow(size);
        for (int i = 0; i < (1 << size); i++) {
            for (int j = 0; j < (1 << size); j++) {
                cout << window[i][j];
            }
            cout << endl;
        }
    }
}  // Accepted: 33921255