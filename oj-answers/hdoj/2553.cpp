#include <iostream>
using namespace std;

constexpr int MAX_SIZE = 100;
int board[MAX_SIZE];
int count[MAX_SIZE];

void print_answers(int size);
void search(int size, int lineIndex = 0);

int main() {
    for (int i = 1; i <= 10; i++) { search(i); }
    int size;
    while (cin >> size && size != 0) { cout << count[size] << endl; }
}

bool available(int m, int n) {
    for (int i = 0; i < m; i++)
        if (board[i] == n || i + board[i] == m + n || i - board[i] == m - n)
            return false;
    return true;
}

void search(int size, int lineIndex) {
    if (lineIndex >= size) {
        count[size]++;
    }
    for (int i = 0; i < size; i++) {
        if (available(lineIndex, i)) {
            board[lineIndex] = i;
            search(size, lineIndex + 1);
        }
    }
}