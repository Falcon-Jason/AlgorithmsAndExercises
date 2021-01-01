#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
struct nomial {
    int expo;
    double coeff;
    nomial(int e = 0, double c = 0) : expo(e), coeff(c) {}
};

bool operator<(const nomial &lhs, const nomial &rhs) {
    if (lhs.expo != rhs.expo)
        return lhs.expo < rhs.expo;
    else
        return lhs.coeff < rhs.coeff;
}

bool operator>(const nomial &lhs, const nomial &rhs) {
    if (lhs.expo != rhs.expo)
        return lhs.expo > rhs.expo;
    else
        return lhs.coeff > rhs.coeff;
}

nomial operator*(const nomial &lhs, const nomial &rhs) {
    return nomial(lhs.expo + rhs.expo, lhs.coeff * rhs.coeff);
}

vector<nomial> get_polynomials() {
    vector<nomial> result;
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        result.push_back(nomial());
        cin >> result.back().expo >> result.back().coeff;
    }
    return result;
}

void put_polynomials(const vector<nomial> &poly) {
    cout << poly.size();
    for (auto i = poly.begin(); i != poly.end(); i++) {
        cout << fixed << " " << setprecision(0) << i->expo << " "
             << setprecision(1) << i->coeff;
    }
    cout << endl;
}

vector<nomial> simplify(vector<nomial> &polynomial) {
    sort(polynomial.begin(), polynomial.end(), greater<nomial>());
    vector<nomial> result;
    result.push_back(polynomial.front());
    for (auto i = polynomial.begin() + 1; i != polynomial.end(); ++i) {
        if (i->expo == result.back().expo) {
            result.back().coeff += i->coeff;
        } else {
            result.push_back(*i);
        }
        if (result.back().coeff == 0) {
            result.pop_back();
        }
    }
    return result;
}

vector<nomial> operator*(const vector<nomial> &lhs, const vector<nomial> &rhs) {
    vector<nomial> result;
    for (int i = 0; i < lhs.size(); i++) {
        for (int j = 0; j < rhs.size(); j++) {
            result.push_back(lhs[i] * rhs[j]);
        }
    }
    return simplify(result);
};

int main() {
    auto i = get_polynomials();
    auto j = get_polynomials();
    put_polynomials(i * j);
    system("PAUSE");
}