#include <iostream>

using namespace std;

bool contains2019(int v) {
    while (v != 0) {
        switch (v % 10) {
            case 2:
            case 0:
            case 1:
            case 9:
                return true;
        }
        v /= 10;
    }
    return false;
}

int main() {
    int range;
    int sum = 0;
    cin >> range;
    for (int i = 1; i <= range; i++) {
        if (contains2019(i)) {
            sum += i;
        }
    }
    cout << sum << endl;
}