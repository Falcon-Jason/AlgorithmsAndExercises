#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>

using namespace std;
using llong = long long;

map<llong, int> squares;

llong digitHash(llong v) {
    if (v == 0) {
        return 1;
    }

    llong hash = 0;
    while (v != 0) {
        int mod = v % 10;
        v /= 10;
        if ((hash & (1 << mod)) != 0) {
            return -1;
        }
        hash |= 1 << mod;
    }
    return hash;
}

void calcSquares() {
    for (llong i = 0; i < 100000; i++) {
        llong sq = i * i;
        llong hash = digitHash(sq);
        if (hash != -1) {
            squares[hash]++;
        }
    }
}

int search(int prev, int set) {
    if (set == 0) {
        return 1;
    }
    int count = 0;
    for (auto& i : squares) {
        if (i.first < prev && (i.first | set) == set) {
            int searched = search(i.first, set - i.first);
            count += i.second * searched;
        }
    }
    return count;
}

int main() {
    squares.clear();
    calcSquares();
    cout << search(65536, 1023) << endl;
}