#include <iostream>
using namespace std;

constexpr int MAX_SIZE = 100;
int answer[MAX_SIZE];

void print_answers(int size);
void search(int size, int lineIndex = 0);

int main() {
    int size;
    cin >> size;
    search(size);
}

bool available(int m, int n) {
    for (int i = 0; i < m; i++)
        if (answer[i] == n || i + answer[i] == m + n || i - answer[i] == m - n)
            return false;
    return true;
}

void search(int size, int lineIndex) {
    if (lineIndex >= size) {
        print_answers(size);
    }
    for (int i = 0; i < size; i++) {
        if (available(lineIndex, i)) {
            answer[lineIndex] = i;
            search(size, lineIndex + 1);
        }
    }
}

void print_answers(int size) {
    static int count = 0;
    cout << ++count << ":";
    for (int i = 0; i < size; i++) {
        cout << " (" << i << "," << answer[i] << ")";
    }
    cout << endl;
}