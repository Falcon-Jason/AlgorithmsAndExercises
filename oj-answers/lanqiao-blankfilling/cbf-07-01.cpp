#include <iostream>
#include <queue>

struct status {
    int step;
    int pos;
};

using namespace std;
int main() {
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (i * 97 - j * 127 == 1) {
                // cout << i << " " << j << endl;
                cout << i + j << endl;
                return 0;
            }
        }
    }
}  // result: 97