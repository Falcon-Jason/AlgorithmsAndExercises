#include <iostream>

using namespace std;

bool balanced(int &w);

int main() {
    int n, w;
    cin >> n;
    cout << (balanced(w) ? "YES" : "NO") << endl;
    for (int i = 1; i < n; i++) {
        cout << endl
             << (balanced(w) ? "YES" : "NO") << endl;
    }
}

bool balanced(int &w) {
    int w1, d1, w2, d2;
    bool res = true;
    cin >> w1 >> d1 >> w2 >> d2;
    if (w1 == 0)
        res &= balanced(w1);
    if (w2 == 0)
        res &= balanced(w2);
    w = w1 + w2;
    return res && w1 * d1 == w2 * d2;
}

// Status: Accepted
// submit: 24487985