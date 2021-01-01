#include <cstring>
#include <deque>
#include <iostream>

using namespace std;

int graph[100][100];
int width, height;

// up, right, down, left
#define NEXT_I(i, pos) (i + next_i[pos])
#define NEXT_J(j, pos) (j + next_j[pos])
#define IN_GRAPH(i, j) \
    ((i) >= 0 && (i) <= height + 1 && (j) >= 0 && (j) <= width + 1)
const int next_i[] = {-1, 0, 1, 0};
const int next_j[] = {0, 1, 0, -1};

bool read_map();
void print_map();
int search_segments(int, int, int, int);

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("tmp-in", "r", stdin);
    freopen("tmp-out", "w", stdout);
#endif
    int board = 0;
    while (read_map()) {
        cout << "Board #" << ++board << ":" << endl;
        int x1, y1, x2, y2;
        int pair = 0;
        while (cin >> x1 >> y1 >> x2 >> y2) {
            if (x1 == 0 || y1 == 0 || x2 == 0 || y2 == 0) {
                break;
            }
            int nseg = search_segments(y1, x1, y2, x2);
            cout << "Pair " << ++pair << ": ";
            if (nseg < 0) {
                cout << "impossible." << endl;
            } else {
                cout << nseg << " segments." << endl;
            }
        }
        cout << endl;
    }

    return 0;
}

struct path {
    int i, j;
};

int nseg[100][100];
int search_segments(int p, int q, int m, int n) {
    deque<path> thequeue{};
    memset(nseg, 0, sizeof(nseg));
    thequeue.push_back({p, q});
    graph[m][n] = nseg[p][q] = 0;

    while (!thequeue.empty()) {
        path p = thequeue.front();
        thequeue.pop_front();
        // cout << p.i << " " << p.j << " " << nseg[p.i][p.j] << endl;
        for (int pos = 0; pos < 4; pos++) {
            int i = NEXT_I(p.i, pos);
            int j = NEXT_J(p.j, pos);
            while (IN_GRAPH(i, j) && !graph[i][j] && !nseg[i][j]) {
                nseg[i][j] = nseg[p.i][p.j] + 1;
                if (i == m && j == n) {
                    graph[m][n] = 1;
                    return nseg[i][j];
                }
                // cout << i << " " << j << " " << nseg[i][j] << endl;
                thequeue.push_back({i, j});
                i = NEXT_I(i, pos);
                j = NEXT_J(j, pos);
            }
        }
    }
    graph[m][n] = 1;
    return -1;
}

bool read_map() {
    cin >> width >> height;
    if (width == 0 || height == 0) {
        return false;
    }
    memset(graph[0], 0, sizeof(*graph));
    memset(graph[height + 1], 0, sizeof(*graph));
    for (int i = 1; i <= height; i++) {
        cin.get();
        graph[i][0] = graph[i][width + 1] = 0;
        for (int j = 1; j <= width; j++) {
            graph[i][j] = cin.get() == 'X';
        }
    }
    return true;
}

void print_map() {
    for (int i = 0; i <= height + 1; i++) {
        for (int j = 0; j <= width + 1; j++) {
            cout << (graph[i][j] ? 'X' : 'O');
        }
        cout << endl;
    }
}

// Status: Accepted