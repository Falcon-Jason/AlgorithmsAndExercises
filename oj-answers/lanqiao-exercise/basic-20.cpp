// http://lx.lanqiao.cn/problem.page?gpid=T61
#include <iostream>

using namespace std;

const char *digit[] = {
    "ling", "yi", "er", "san", "si",
    "wu", "liu", "qi", "ba", "jiu",
    "shi", "bai", "qian", "wan", "yi"};

#define BAI 11
#define QIAN 12
#define WAN 13
#define YI 14

bool no_print = true;
void print_single_digit(int n) {
    if (!no_print) {
        cout << " " << digit[n];
    } else {
        no_print = false;
        cout << digit[n];
    }
}

void print_dual_digit(int n, bool is_head) {
    if (!is_head || n < 10 || n >= 20) {
        print_single_digit(n / 10);
    }
    print_single_digit(10);
    if (n % 10 != 0) {
        print_single_digit(n % 10);
    }
}

void print_tri_digit(int n) {
    print_single_digit(n / 100);
    print_single_digit(BAI);
    int t = n % 100;
    if (t > 0 && t < 10) {
        print_single_digit(0);
        print_single_digit(n % 10);
    } else if (t >= 10) {
        print_dual_digit(t, false);
    }
}

bool print_quad_digit(int n, bool is_head) {
    int t = n / 1000;
    if (t != 0) {
        print_single_digit(t);
        print_single_digit(QIAN);
    }

    n %= 1000;
    if (n / 100 != 0) {
        if (t == 0 && !is_head) {
            print_single_digit(0);
        }
        print_tri_digit(n);
        return true;
    }

    if (n != 0 && ((n != 0) ^ (is_head))) {
        print_single_digit(0);
    }

    n %= 100;
    if (n / 10 != 0) {
        print_dual_digit(n, is_head);
        return true;
    }

    n %= 10;
    if (n != 0) {
        print_single_digit(n);
        return true;
    }
    return false;
}

int main() {
    int n;
    bool is_head = true;
    cin >> n;

    if (n == 0) {
        print_single_digit(0);
        cout << endl;
        return 0;
    }

    if (print_quad_digit(n / 100000000, is_head)) {
        print_single_digit(YI);
        is_head = false;
    }
    if (print_quad_digit(n / 10000 % 10000, is_head)) {
        print_single_digit(WAN);
        is_head = false;
    }
    print_quad_digit(n % 10000, is_head);
    cout << endl;
}

// Status: Accepted
// Submit: 5118213