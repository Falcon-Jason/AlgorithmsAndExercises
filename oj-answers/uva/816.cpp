#include <array>
#include <iostream>
#include <list>
#include <map>
#include <queue>

using namespace std;

void init_graph();
void read_graph();
void calc_path();
void print_path();
string graph_name;

int main() {
#ifndef ONLINE_JUDGE
    freopen("tmp-in", "r", stdin);
    freopen("tmp-out", "w", stdout);
#endif
    while (cin >> graph_name && graph_name != "END") {
        init_graph();
        read_graph();
        calc_path();
        print_path();
    }
}
// using path = tuple<int, int, int>;

struct path {
    int i;
    int j;
    int dir;
    path(int _i = 0, int _j = 0, int _dir = 0) : i{_i}, j{_j}, dir{_dir} {}
    bool operator==(const path &rhs) const {
        return i == rhs.i && j == rhs.j && dir == rhs.dir;
    }
};

list<path> graph[11][11][4];
int begin_i, begin_j, begin_dir;
int end_i, end_j;

void init_graph() {
    for (auto i = graph; i < *(&graph + 1); ++i) {
        for (auto j = *i; j < *(i + 1); ++j) {
            for (auto k = *j; k < *(j + 1); k++) {
                k->clear();
            }
        }
    }
}

constexpr int N = 0, E = 1, W = 2, S = 3;
constexpr int F = 0, L = 1, R = 2;

const map<char, int> directions{{'N', N}, {'E', E}, {'W', W}, {'S', S}, {'F', F}, {'L', L}, {'R', R}};

const int turning[4][3] = {
    {0, 2, 1},
    {1, 0, 3},
    {2, 3, 0},
    {3, 1, 2},
};

// const int reversed[4] = {S, W, E, N};

const int next_i[] = {-1, 0, 0, 1};
const int next_j[] = {0, 1, -1, 0};

#define TURNTO(dir, turn) turning[dir][turn]
#define NEXT_I(i, dir) ((i) + next_i[dir])
#define NEXT_J(j, dir) ((j) + next_j[dir])
#define DIR(x) directions.at(x)

void add_path(int i, int j, int dir, int turn);

void read_graph() {
    string tmp;
    int x, y;
    // read begin and end
    cin >> begin_i >> begin_j >> tmp >> end_i >> end_j;
    begin_dir = DIR(tmp[0]);
    while (cin >> x && x != 0) {
        cin >> y;
        while (cin >> tmp && tmp[0] != '*') {
            auto i = tmp.begin();
            int dir = DIR(*i);
            for (++i; i != tmp.end(); ++i) {
                add_path(x, y, dir, DIR(*i));
            }
        }
    }
}

void add_path(int i, int j, int dir, int turn) {
    int ndir = TURNTO(dir, turn);
    graph[i][j][dir].push_back(path(NEXT_I(i, ndir), NEXT_J(j, ndir), ndir));
    // cout << i << " " << j << " " << "NEWS"[dir] << "NEWS"[ndir] << endl;
    // cout << "->  " << NEXT_I(i, ndir) << " " << NEXT_J(j, ndir) << " " <<
    // "NEWS"[ndir] << endl;
}

list<path> *result;
bool availableToAdd(const list<path> &l, const path &p);
ostream &operator<<(ostream &out, list<path> *res);

void calc_path() {
    int i = NEXT_I(begin_i, begin_dir);
    int j = NEXT_J(begin_j, begin_dir);
    int dir = begin_dir;

    if (i == end_i && j == end_j) {
        result = new list<path>{path{i, j, dir}};
        return;
    }

    list<list<path> *> thequeue{};
    thequeue.push_back(new list<path>{path(i, j, dir)});

    while (thequeue.size()) {
        list<path> *p = thequeue.front();
        thequeue.pop_front();

        path current = p->back();
        list<path> *l = &graph[current.i][current.j][current.dir];
        // cout << current.i << " " << current.j << " " << "NEWS"[current.dir]
        // << endl; cout << "p: " << p << endl; cout << "l: " << l << endl;
        for (auto itor = l->begin(); itor != l->end(); ++itor) {
            if (availableToAdd(*p, *itor)) {
                if (itor->i == end_i && itor->j == end_j) {
                    p->push_back(*itor);
                    result = p;
                    while (thequeue.size()) {
                        delete thequeue.back();
                        thequeue.pop_back();
                    }
                    return;
                } else {
                    list<path> *new_path = new list<path>{*p};
                    new_path->push_back(*itor);
                    thequeue.push_back(new_path);
                }
            }
        }
        delete p;
    }
    result = nullptr;
}

bool availableToAdd(const list<path> &l, const path &p) {
    if (p.i < 0 || p.i > 9 || p.j < 0 || p.j > 9)
        return false;
    for (auto i = l.begin(); i != l.end(); ++i) {
        if (p == *i) {
            return false;
        }
    }
    return true;
}

void print_path() {
    cout << graph_name << endl;
    if (result == nullptr)
        cout << "  No Solution Possible" << endl;
    else
        cout << "  (" << begin_i << "," << begin_j << ")" << result << endl;
    delete result;
}

ostream &operator<<(ostream &out, list<path> *res) {
    int n = 2;
    for (auto i = res->begin(); i != res->end(); ++i) {
        if (n++ % 10 == 1)
            out << endl
                << " ";
        out << " (" << i->i << "," << i->j << ")";
    }
    return out;
}

// Status: Accepted
// Submit: 24511837