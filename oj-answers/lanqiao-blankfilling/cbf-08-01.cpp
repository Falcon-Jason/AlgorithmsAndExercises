#include <iostream>

using namespace std;

int main() {
    int v[] = {'m' - 'a' + 10, 'n' - 'a' + 10, 'a' - 'a' + 10, 'y' - 'a' + 10};
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum *= 36;
        sum += v[i];
    }
    cout << sum << endl;
}

// Result: 1056634