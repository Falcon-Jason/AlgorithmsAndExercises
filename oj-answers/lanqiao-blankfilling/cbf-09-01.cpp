#include <iostream>

using namespace std;

int main() {
    int min = 1000;
    for (int i = 1; i < 200 / 21; i++) {
        if ((200 - 21 * i) % 5 == 0) {
            int cur = i * 11 + (200 - 21 * i) / 5;
            if (cur < min) {
                min = cur;
            }
        }
    }
    cout << min << endl;
}

// Result: 74