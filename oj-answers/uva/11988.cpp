#include <cctype>
#include <cstdio>
#define SIZE 110000
using namespace std;

char raw[SIZE];
char text[SIZE]{0};
int next[SIZE]{0};
int cur, end, empty;

bool read_text() {
    next[0] = -1;
    cur = 0;
    end = 0;
    empty = 1;
    if (!fgets(raw, SIZE, stdin))
        return false;
    for (int i = 0; raw[i] && raw[i] != '\n'; i++) {
        if (raw[i] == '[') {
            cur = 0;
        } else if (raw[i] == ']') {
            cur = end;
        } else {
            next[empty] = next[cur];
            next[cur] = empty++;
            cur = next[cur];
            text[cur] = raw[i];
        }
        if (next[cur] == -1) {
            end = cur;
        }
    }
    return true;
}

void print_text() {
    for (int i = next[0]; i != -1; i = next[i]) {
        putchar(text[i]);
    }
    putchar('\n');
}

int main() {
    while (read_text()) {
        print_text();
    }
}

// Status: Accepted
// Submit: 24313116