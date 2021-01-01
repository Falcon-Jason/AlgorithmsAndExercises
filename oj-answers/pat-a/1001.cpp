#include <iostream>
#include <stack>

using namespace std;

void printd(int n) {
    if (n == 0) {
        putchar('0');
        return;
    }
    if (n > 0 && n < 1000) {
        printf("%d", n);
    } else {
        printd(n / 1000);
        printf(",%03d", n % 1000);
    }
}

int main() {
    int a, b;
    int c;
    cin >> a >> b;
    c = a + b;

    if (c < 0) {
        putchar('-');
        c = -c;
    }

    printd(c);
    putchar('\n');
    return 0;
}