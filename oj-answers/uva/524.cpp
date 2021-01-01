#include <cstring>
#include <iostream>
#define PRIME_SZ 32

using namespace std;

int prime[PRIME_SZ] = {0};
int used[20] = {0, 1};
int circle[20] = {1};
int circle_sz;

void calc_prime();
void print_circle();
void search(int p);

int main() {
#ifndef ONLINE_JUDGE
    freopen("tmp-out", "w", stdout);
#endif
    int kase = 0;
    while (cin >> circle_sz) {
        cout << (kase ? "\n" : "");
        cout << "Case " << ++kase << ":" << endl;
        calc_prime();
        search(1);
    }
}

void calc_prime() {
    for (int i = 2; i < PRIME_SZ; i++) {
        prime[i] = 1;
    }

    for (int i = 2; i < PRIME_SZ; i++) {
        if (prime[i]) {
            for (int j = i * 2; j < PRIME_SZ; j += i) {
                prime[j] = 0;
            }
        }
    }
}

void search(int p) {
    if (p == circle_sz) {
        if (prime[circle[p - 1] + circle[0]]) {
            print_circle();
        }
        return;
    }

    for (int i = 1; i <= circle_sz; i++) {
        if (!used[i] && prime[i + circle[p - 1]]) {
            used[i] = 1;
            circle[p] = i;
            search(p + 1);
            used[i] = 0;
        }
    }
}

void print_circle() {
    cout << circle[0];
    for (int i = 1; i < circle_sz; i++) {
        cout << " " << circle[i];
    }
    cout << endl;
}

// Status: Accepted
// Submit: 24697874