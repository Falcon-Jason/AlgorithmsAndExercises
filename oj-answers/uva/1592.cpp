#include <iostream>
#include <map>
#include <string>

using namespace std;

int table[16384][16];
int nrow, ncol;

void get_table();
void match_pnf();

int main() {
    while (cin >> nrow >> ncol) {
        get_table();
        match_pnf();
    }
}

map<string, int> items;
int get_item();

void get_table() {
    items.clear();
    for (int i = 0; i < nrow; i++) {
        for (int j = 0; j < ncol; j++) {
            table[i][j] = get_item();
        }
    }
}

void match_pnf() {
    for (int c1 = 0; c1 < ncol; c1++) {
        for (int c2 = c1 + 1; c2 < ncol; c2++) {
            map<pair<int, int>, int> data{};
            for (int i = 0; i < nrow; i++) {
                auto item = make_pair(table[i][c1], table[i][c2]);
                if (data.count(item)) {
                    cout << "NO" << endl;
                    cout << data.at(item) + 1 << " " << i + 1 << endl;
                    cout << c1 + 1 << " " << c2 + 1 << endl;
                    return;
                }
                data.insert(make_pair(item, i));
            }
        }
    }
    cout << "YES" << endl;
}

int get_item() {
    string str;
    do {
        char c;
        while ((c = cin.get()) != ',' && c != '\n') {
            str.push_back(c);
        }
    } while (str.empty());
    if (!items.count(str)) {
        items.insert(make_pair(str, items.size()));
    }
    return items.at(str);
}

// Status: Accepted
// Submit: 24476526