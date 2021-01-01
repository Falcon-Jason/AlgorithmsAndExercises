#include <iostream>
#include <set>

#define HEIGHT 3
#define WIDTH 10
#define X 1
#define Y -1
#define EMPTY 0

using namespace std;

int ground[HEIGHT + 2][WIDTH + 2]{{EMPTY}};

set<int> result;

int groundHash() {
    int hash = 0;
    for (int i = 1; i <= HEIGHT; i++) {
        for (int j = 1; j <= WIDTH; j++) {
            hash <<= 1;
            hash |= (ground[i][j] == X);
        }
    }
    return hash;
}

bool placeable(int i, int j, int dir) {
    if (dir == 0) {
        return ground[i][j] == EMPTY && i <= HEIGHT && j < WIDTH && ground[i][j + 1] == EMPTY;
    } else {
        return ground[i][j] == EMPTY && i < HEIGHT && j <= WIDTH && ground[i + 1][j] == EMPTY;
    }
}

bool isAvailable() {
    for (int i = 1; i <= HEIGHT; i++) {
        for (int j = 1; j <= WIDTH; j++) {
            int sum = ground[i][j] + ground[i][j + 1] + ground[i + 1][j] + ground[i + 1][j + 1];
            if (sum == 4 || sum == -4) {
                return false;
            }
        }
    }
    return true;
}

void nextPos(int i, int j, int *nexti, int *nextj) {
    *nexti = i;
    *nextj = j;
    for (;; ++*nexti) {
        for (; *nextj <= WIDTH; ++*nextj) {
            if (ground[*nexti][*nextj] == EMPTY) {
                return;
            }
        }
        *nextj = 1;
    }
}

void search(int i, int j) {
    if (i > HEIGHT || j > WIDTH) {
        if (isAvailable()) {
            result.insert(groundHash());
        }
    }

    if (placeable(i, j, 0)) {
        int next_i, next_j;

        ground[i][j + 1] = ground[i][j] = X;
        nextPos(i, j, &next_i, &next_j);
        search(next_i, next_j);
        ground[i][j + 1] = ground[i][j] = Y;
        search(next_i, next_j);
        ground[i][j + 1] = ground[i][j] = EMPTY;
    }
    if (placeable(i, j, 1)) {
        int next_i, next_j;

        ground[i + 1][j] = ground[i][j] = X;
        nextPos(i, j, &next_i, &next_j);
        search(next_i, next_j);
        ground[i + 1][j] = ground[i][j] = Y;
        search(next_i, next_j);
        ground[i + 1][j] = ground[i][j] = EMPTY;
    }
}

int main() {
    search(1, 1);
    cout << result.size() << endl;
}  // Result: 101466