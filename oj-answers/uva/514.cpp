#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool available();
int count, buffer[1100];

int main() {
    for (cin >> count; count != 0; cin >> count) {
        for (cin >> buffer[0]; buffer[0] != 0; cin >> buffer[0]) {
            for (int i = 1; i < count; i++) {
                cin >> buffer[i];
            }
            cout << (available() ? "Yes" : "No") << endl;
        }
        cout << endl;
    }
    return 0;
}

bool available() {
    int n = 0;
    stack<int> s;
    for (int i = 0; i < count; i++) {
        while (n < buffer[i]) {
            s.push(++n);
        }
        if (s.top() == buffer[i]) {
            s.pop();
        } else {
            return false;
        }
    }
    return true;
}

// Status: Accepted
// Submit: 24302179