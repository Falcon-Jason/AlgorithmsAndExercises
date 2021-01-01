#include <cctype>
#include <iostream>
#include <stack>
#define skip_line() for (int c = cin.get(); c != '\n'; c = cin.get())
using namespace std;

struct matrix {
    int row, column;
    matrix(int r = 0, int c = 0) : row{r}, column{c} {}
} m[26];

int mul(matrix &m1, matrix &m2) { return m1.row * m2.row * m2.column; }

void readm() {
    string s;
    int a, b, c;
    cin >> s >> b >> c;
    a = s[0] - 'A';
    m[a].row = b;
    m[a].column = c;
}

int multimes() {
    stack<matrix> s;
    int times = 0;
    int c = cin.get();
    if (c == EOF) {
        return -2;
    }
    for (; c != '\n'; c = cin.get()) {
        if (isalpha(c)) {
            s.push(m[c - 'A']);
        } else if (c == ')' && s.size() >= 2) {
            auto m2 = s.top();
            s.pop();
            auto m1 = s.top();
            s.pop();
            if (m1.column != m2.row) {
                skip_line();
                return -1;
            }
            s.push(matrix(m1.row, m2.column));
            times += mul(m1, m2);
        } else if (c != '(') {
            skip_line();
            return -1;
        }
    }
    return times;
}

int main() {
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        readm();
    }
    skip_line();
    for (count = multimes(); count != -2; count = multimes()) {
        if (count == -1) {
            printf("error\n");
        } else {
            printf("%d\n", count);
        }
    }
}

// Status: Accepter
// Submit: 24312829