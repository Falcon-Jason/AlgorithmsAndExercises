#include <cstring>
#include <iostream>

inline int cmp_substring(const char* substr, int begin, int end) {
    return strncmp(substr + begin, substr + end, end - begin);
}

using namespace std;

char sequence[100];
int target_index;
int current_index;
int ch_limit;

bool is_hard_str(int seq_size) {
    if (seq_size == 0) {
        return 0;
    }

    for (int i = 1; i <= seq_size / 2; i++) {
        if (!cmp_substring(sequence, seq_size - 2 * i, seq_size - i)) {
            return false;
        }
    }
    return true;
}

void search(int seq_size = 0) {
    for (int i = 0; i < ch_limit; i++) {
        if (current_index >= target_index) {
            return;
        }
        sequence[seq_size] = 'A' + i;
        if (is_hard_str(seq_size + 1)) {
            sequence[seq_size + 1] = 0;
            current_index++;
            search(seq_size + 1);
        }
    }
}

void print_sequence() {
    int i;
    cout << sequence[0];
    for (i = 1; sequence[i]; i++) {
        // (!(i % 4) ? " " : "")
        if (!(i % 4)) {
            cout << ((!(i % (16 * 4))) ? "\n" : " ");
        }
        cout << sequence[i];
    }
    cout << endl
         << i << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("tmp-out", "w", stdout);
#endif
    while (cin >> target_index >> ch_limit) {
        if (target_index == 0 || ch_limit == 0) {
            break;
        }
        current_index = 0;
        search();
        // cout << sequence << endl;
        print_sequence();
    }
}

// Status: Accepted
// Submit: 24703094