#include <cstring>
#include <iostream>
constexpr int ARRSIZE = 32;

using namespace std;

bool prime[ARRSIZE] = {
    0, 0, 1, 1, 0, 1, 0, 1,
    0, 0, 0, 1, 0, 1, 0, 0,
    0, 1, 0, 1, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 1, 0, 1};

int ring[ARRSIZE] = {1};
int used[ARRSIZE] = {0, 1};

void printRing(int len) {
    cout << ring[0];
    for (int i = 1; i < len; i++) {
        cout << ' ' << ring[i];
    }
    cout << endl;
}

void search(int cur, int len) {
    if (cur == len) {
        if (prime[ring[cur - 1] + 1]) {
            printRing(len);
        }
        return;
    }

    for (int i = 1; i <= len; i++) {
        if (!used[i] && prime[ring[cur - 1] + i]) {
            used[i] = true;
            ring[cur] = i;
            search(cur + 1, len);
            used[i] = false;
        }
    }
}

int main(int argc, char const *argv[]) {
    int len;
    int kase = 0;
    while (cin >> len) {
        cout << (kase ? "\n" : "");
        cout << "Case " << ++kase << ":" << endl;
        search(1, len);
    }
    return 0;
}

// Status: Accepted
// Submit: 25567257