#include <bitset>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

constexpr int MAX_H = 200;
constexpr int MAX_W = 50 * 4;

const int next_x[4] = {0, 1, 0, -1};
const int next_y[4] = {1, 0, -1, 0};
int connection[MAX_H + 5][MAX_W + 5];

int cur_i = 0, cur_j = 0;
int height, width;

int readPicture();

int searchHieroglyph();
void searchConnection();
void printConnection();
void printPicture();
void searchConnection(int i, int j, int conid);
void searchHieroglyph(int i, int j, set<int> &res);

const char alphabet[] = {'\0', 'W', 'A', 'K', 'J', 'S', 'D'};
const int order[] = {2, 6, 4, 3, 5, 1};
int main() {
    string line;
    int n = 0;
    int hier;
    while (readPicture()) {
        int count[7] = {0};
        cout << "Case " << ++n << ": ";
        cur_i = cur_j = 0;
        memset(connection, 0, sizeof(connection));
        searchConnection();
        while ((hier = searchHieroglyph()) != 0) {
            count[hier]++;
        }
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < count[order[i]]; j++) {
                cout << alphabet[order[i]];
            }
        }
        cout << endl;
    }
}

int searchHieroglyph() {
    set<int> res{};
    for (; cur_i < height; cur_i++) {
        for (; cur_j < width; cur_j++) {
            if (!connection[cur_i][cur_j]) {
                searchHieroglyph(cur_i, cur_j, res);
                return res.size();
            }
        }
        cur_j = 0;
    }
    return 0;
}

void searchHieroglyph(int i, int j, set<int> &res) {
    connection[i][j] = -1;
    for (int n = 0; n < 4; n++) {
        int x = i + next_x[n];
        int y = j + next_y[n];
        // cout << " " << x << " " << y << endl;
        if (x < 0 || x > height || y < 0 || y > width)
            continue;
        if (connection[x][y] && connection[x][y] != -1) {
            res.insert(connection[x][y]);
        } else if (connection[x][y] != -1) {
            searchHieroglyph(x, y, res);
        }
    }
}

bitset<MAX_W + 5> picture[MAX_H + 5];
int connectBorder();

void searchConnection() {
    while (connectBorder())
        ;
    int conid = 1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (!picture[i][j] && !connection[i][j]) {
                // cerr << i << " " << j << endl;
                searchConnection(i, j, ++conid);
            }
        }
    }
}

void searchConnection(int i, int j, int conid) {
    connection[i][j] = conid;
    for (int n = 0; n < 4; n++) {
        const int x = i + next_x[n];
        const int y = j + next_y[n];
        if (x < 0 || x > height || y < 0 || y > width)
            continue;
        if (!picture[x][y] && !connection[x][y]) {
            searchConnection(x, y, conid);
        }
    }
}

int connectBorder() {
    int nc = 0;
    for (int i = 0; i < width; i++) {
        connection[0][i] = connection[height - 1][i] = 1;
    }
    for (int j = 0; j < height; j++) {
        connection[j][0] = connection[j][width - 1] = 1;
    }
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            for (int n = 0; n < 4; n++) {
                const int x = i + next_x[n];
                const int y = j + next_y[n];
                if (connection[x][y] == 1 && !picture[i][j]) {
                    nc += connection[i][j] ? 0 : 1;
                    connection[i][j] = 1;
                    break;
                }
            }
        }
    }
    return nc;
}

void printConnection() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << connection[i][j];
        }
        cout << endl;
    }
}

void printPicture() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << picture[i][j];
        }
        cout << endl;
    }
}

void setBitmap(int i, int j, int val);
int readPicture() {
    string line;
    getline(cin, line);
    sscanf(line.c_str(), "%d%d", &height, &width);
    if (height == 0 || width == 0) {
        return 0;
    }
    for (int i = 1; i <= height; i++) {
        getline(cin, line);
        picture[i].reset();
        for (int j = 0; j < width; j++) {
            setBitmap(i, j * 4,
                      isdigit(line[j]) ? line[j] - '0' : line[j] - 'a' + 10);
        }
    }
    height += 2;
    width *= 4;
    width += 2;
    picture[0].reset();
    picture[height - 1].reset();
    return 1;
}

void setBitmap(int m, int n, int val) {
    for (int i = n + 4; i > n; i--) {
        picture[m][i] = val & 1;
        val >>= 1;
    }
}

// Status: Accepted
// Submit: 24502051