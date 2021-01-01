#include <cstring>
#include <iostream>
#define SIZE 120

using namespace std;

char paper[SIZE][SIZE] = {{0}};
char badPos[SIZE][SIZE] = {{0}};

int width;
int height;

int searchLayer(int layer);
int setLayer(int layer, int start);

void printLayer() {
    for (int i = height; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            cout << (int)paper[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

inline bool placeable(int i, int j) {
    return !badPos[i][j] && paper[i - 1][j];
}

int setLayer(int layer, int start) {
    int count = 0;
    for (int i = start; i < width && placeable(layer, i); i++) {
        paper[layer][i] = 1;
        count += searchLayer(layer + 1);
    }
    return count;
}

int searchLayer(int layer) {
    if (layer > height) {
        // printLayer();
        return 1;
    }

    int count = 1;
    for (int i = 0; i < width; i++) {
        if (placeable(layer, i)) {
            memset(paper[layer], 0, width);
            count += setLayer(layer, i);
        }
    }

    return count;
}

void readBadPos() {
    for (int i = height; i > 0; i--) {
        fgets(badPos[i], SIZE, stdin);
        for (int j = 0; j < width; j++) {
            badPos[i][j] = (badPos[i][j] == 'X');
        }
    }
}

int main() {
    string buffer;
    getline(cin, buffer);
    sscanf(buffer.c_str(), "%d%d", &height, &width);
    readBadPos();
    memset(paper[0], 1, width);
    cout << searchLayer(1) << endl;
}

// TLE