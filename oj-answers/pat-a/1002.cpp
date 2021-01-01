#include <iomanip>
#include <iostream>
#include <list>

using namespace std;

struct Monomial {
    double coefficient;  // 系数
    int exponents;       // 指数

    Monomial(double coeff = 0.0, int expo = 0) {
        coefficient = coeff;
        exponents = expo;
    }

    friend ostream &operator<<(ostream &out, Monomial &mon) {
        out << mon.exponents << " " << setprecision(1) << fixed << mon.coefficient;
        return out;
    }
};

struct Polymial {
    list<Monomial> items;  // 按指数递减的顺序存放多项式中的每一项
    Polymial() : items() {}

    void clearZeroItems() {
        for (auto i = items.begin(); i != items.end(); i++) {
            if (i->coefficient == 0)
                items.erase(i++);
        }
    }

    Polymial &operator+=(Polymial &rhs) {
        for (auto i = items.begin(), j = rhs.items.begin(); j != rhs.items.end();) {
            if (i == items.end()) {
                items.push_back(*(j++));
            } else if (i->exponents > j->exponents) {
                i++;
            } else if (i->exponents == j->exponents) {
                (i++)->coefficient += (j++)->coefficient;
            } else {
                items.insert(i, *(j++));
            }
        }
        clearZeroItems();
        return *this;
    }

    friend ostream &operator<<(ostream &out, Polymial &pol) {
        out << pol.items.size();

        for (auto i = pol.items.begin(); i != pol.items.end(); i++) {
            out << " " << *i;
        }
        return out;
    }

    friend istream &operator>>(istream &in, Polymial &pol) {
        pol.items.clear();
        int size;
        in >> size;
        for (int i = 0; i < size; i++) {
            double coeff;
            int expo;
            in >> expo >> coeff;
            pol.items.push_back(Monomial(coeff, expo));
        }
        return in;
    }
};

int main() {
    Polymial p1, p2;
    cin >> p1 >> p2;
    cout << (p1 += p2) << endl;
    return 0;
}