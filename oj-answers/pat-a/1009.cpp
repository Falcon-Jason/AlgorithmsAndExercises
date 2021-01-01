#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

using octo = unsigned long long;

unordered_map<char, int> alphabet;
void init_alphabet() {
    for (int i = '0'; i <= '9'; i++) {
        alphabet[i] = i - '0';
    }
    for (int i = 'a'; i <= 'z'; i++) {
        alphabet[i] = i - 'a' + 10;
    }
}

octo scan_int(const string &n, int radix) {
    octo val = 0;
    for (auto i = n.begin(); i != n.end(); ++i) {
        val *= radix;
        val += alphabet[*i];
    }
    return val;
}

int main() {
    init_alphabet();
    string n1_s, n2_s;
    octo n1, n2;
    int tag, radix;
    cin >> n1_s >> n2_s >> tag >> radix;
    if (tag == 2) {
        swap(n1_s, n2_s);
    }
    n1 = scan_int(n1_s, radix);
    for (int i = 2; i <= 36; i++) {
        n2 = scan_int(n2_s, i);
        if (n2 == n1) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
}