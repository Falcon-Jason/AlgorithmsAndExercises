#include <iostream>
#define SIZE 30

int lights[SIZE];

int search(int pos) {
    if (pos >= SIZE) {
        return 1;
    }

    int count = 0;
    lights[pos] = 1;
    count += search(pos + 2);
    lights[pos] = 0;
    count += search(pos + 1);
    return count;
}

using namespace std;
int main() {
    cout << search(0) << endl;
}

// Result: 2178309