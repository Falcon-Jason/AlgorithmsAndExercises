#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;


struct BigInt
{
    string val;
    BigInt() { this->val = "0"; }
    BigInt(string &s) { this->val = s; }
    BigInt(const char *s) { this->val = s; }

    static void Zeroize(BigInt &a,BigInt &b)
    {
        if(a.val.size() > b.val.size()){
            int size = a.val.size() - b.val.size();
            for (int i = 0; i < size; i++)
            {
                b.val.insert(0, "0");
            }
        }
        else{
            int size = b.val.size() - a.val.size();
            for (int i = 0; i < size; i++)
            {
                a.val.insert(0, "0");
            }
        }
    }

    friend BigInt operator-(BigInt &a,BigInt &b)
    {
        Zeroize(a, b);
        BigInt c{a};
        for (int i = c.val.size() - 1; i >= 0;i--){
            c.val[i] -= b.val[i] - '0';
            if(c.val[i] < '0'){
                c.val[i] += 10;
                c.val[i - 1]--;
            }
        }
        return c;
    }

    void print(ostream &out){
        int i = 0;
        while(this->val[i]=='0'){
            i++;
        }
        out << this->val.substr(i, this->val.size());
    }
};

int main()
{
    string s{};
    while(cin >> s)
    {
        int pos = s.find('-');
        string sa = s.substr(0, pos);
        string sb = s.substr(pos + 1, s.size());
        BigInt a{sa};
        BigInt b{sb};
        BigInt::Zeroize(a, b);
        // cout << a.val << endl;
        // cout << b.val << endl;
        (a - b).print(cout);
    }
}