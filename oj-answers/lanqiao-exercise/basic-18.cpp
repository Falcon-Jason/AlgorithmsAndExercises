#include <algorithm>
#include <iostream>
using namespace std;

struct square {
    double a, b;
    double c, d;
};

void make_square(square& sq) {
    if (sq.a > sq.c) {
        swap(sq.a, sq.c);
    }
    if (sq.b < sq.d) {
        swap(sq.b, sq.d);
    }
}

double square_area(square& sq) {
    double res = (sq.c - sq.a) * (sq.b - sq.d);
    return res <= 0 ? 0 : res;
}

square square_cross(square s1, square s2) {
    if (s1.a > s2.a) {
        swap(s1, s2);
    }
    return s1.c < s2.a || s1.d > s2.b
               ? square{0, 0, 0, 0}
               : square{max(s1.a, s2.a), min(s1.b, s2.b), min(s1.c, s2.c), max(s1.d, s2.d)};
}

istream& operator>>(istream& in, square& sq) {
    in >> sq.a >> sq.b >> sq.c >> sq.d;
    make_square(sq);
    return in;
}

int main() {
    square s1, s2;
    cin >> s1 >> s2;
    square cross = square_cross(s1, s2);
    printf("%.2lf\n", square_area(cross));
    return 0;
}

// Status: Accepted
// Submit: 4959979