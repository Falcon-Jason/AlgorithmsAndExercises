#include <iostream>
#include <vector>
using namespace std;

class QNum
{
private:
    vector<int> div;
    vector<int> mod;
    int circlePos;

public:
    QNum(int Numerator, int denominator)
    {
        div.clear();
        mod.clear();
        div.push_back(Numerator * 10 / denominator);
        mod.push_back(Numerator * 10 % denominator);
        while (mod.back() != 0 && findCircle() == -1)
        {
            div.push_back(mod.back() * 10 / denominator);
            mod.push_back(mod.back() * 10 % denominator);
        }
        div[0] %= 10;
        if(mod.back() == 0)
        {
            circlePos = -1;
        }
        else
        {
            circlePos = findCircle();
        }
        
    }

    friend ostream &operator<<(ostream &out, const QNum &q)
    {
        for (int i = 0; i < q.div.size();i++)
        {
            out << q.div[i] << " ";
        }
        out << endl;
        for (int i = 0; i < q.mod.size();i++)
        {
            out << q.mod[i] << " ";
        }
        return out;
    }

    int operator[](int i)
    {
        int size = div.size();
        if(i < size)
        {
            return div[i];
        }
        if(circlePos == -1)
        {
            return 0;
        }
        return div[circlePos + (i - circlePos) % (size - circlePos - 1)];
    }

    int findCircle()
    {
        int vald = div[div.size() - 1];
        int valm = mod[mod.size() - 1];
        for (int i = 0; i < div.size() - 1; i++)
        {
            if (div[i] == vald && mod[i] == valm)
                return i;
        }
        return -1;
    }
};

bool containsTail(const vector<int> &v);
void generateValArray(int m, int n);
int divTail(int n);

int circlePos;

int main()
{
    long long a, b, n;
    cin >> a >> b >> n;
    QNum q(a, b);
    // cout << q << endl;
    cout << q[n - 1] << q[n] << q[n + 1];
}