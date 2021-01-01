#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

list<int> thelist;
list<int>::iterator nodes[100100];

void init_nodes(int n);
void move_nodes(int position, int s, int t);
void swap_nodes(int p, int q);

template <typename iterator>
long long odd_sum(iterator begin, iterator end);

list<int>::iterator last(list<int>::iterator i) { return --i; }
list<int>::iterator next(list<int>::iterator i) { return ++i; }

int main() {
    int n, m, kase = 0;
    while (cin >> n >> m) {
        init_nodes(n);
        bool reversed = false;
        for (int i = 0; i < m; i++) {
            int op, x, y;
            cin >> op;
            switch (op) {
                case 1:
                case 2:
                    cin >> x >> y;
                    move_nodes((op - 1) ^ reversed, x, y);
                    break;

                case 3:
                    cin >> x >> y;
                    swap_nodes(x, y);
                    break;

                case 4:
                    reversed = !reversed;
                    break;
            }
        }
        if (reversed)
            cout << "Case " << ++kase << ": "
                 << odd_sum(thelist.rbegin(), thelist.rend()) << endl;
        else
            cout << "Case " << ++kase << ": "
                 << odd_sum(thelist.begin(), thelist.end()) << endl;
    }
}

void init_nodes(int n) {
    thelist.clear();
    for (int i = 0; i <= n + 1; i++) {
        thelist.push_back(i);
        nodes[i] = --thelist.end();
    }
}

void move_nodes(int position, int s, int t) {
    if (position == 0 && next(nodes[s]) != nodes[t]) {
        thelist.erase(nodes[s]);
        nodes[s] = thelist.insert(nodes[t], s);
    } else if (position == 1 && next(nodes[t]) != nodes[s]) {
        thelist.erase(nodes[s]);
        nodes[s] = thelist.insert(next(nodes[t]), s);
    }
}

void swap_nodes(int p, int q) {
    swap(*nodes[p], *nodes[q]);
    swap(nodes[p], nodes[q]);
}

template <typename iterator>
long long odd_sum(iterator begin, iterator end) {
    ++begin;  // 跳过头结点
    --end;    // 跳过尾节点
    bool isodd = true;
    long long sum = 0;
    for (iterator i = begin; i != end; ++i) {
        sum += isodd ? *i : 0;
        isodd = !isodd;
    }
    return sum;
}

// Status: Accepted
// Submit: 24505303