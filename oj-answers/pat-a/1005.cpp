#include <iostream>
#include <stack>
using namespace std;

string digitname[] = {"zero", "one", "two", "three", "four",
                      "five", "six", "seven", "eight", "nine"};

void putint(int d, ostream &out = cout) {
    stack<int> s{};
    do {
        s.push(d % 10);
        d /= 10;
    } while (d != 0);
    out << digitname[s.top()];
    s.pop();
    while (!s.empty()) {
        out << " " << digitname[s.top()];
        s.pop();
    }
    out << endl;
}

int main() {
    int ch;
    int sum = 0;
    while (isdigit(ch = cin.get())) {
        sum += ch - '0';
    }
    putint(sum);
}