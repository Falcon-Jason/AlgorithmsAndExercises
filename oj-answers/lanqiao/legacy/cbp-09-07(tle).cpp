#include <iostream>
#include <algorithm>

using namespace std;

struct point
{
    int step;
    int x;
    int y;

    point(int x = 0, int y = 0)
    {
        step = max(abs(x), abs(y));
        this->x = x;
        this->y = y;
    }

    point &operator++()
    {
        if (x == -step && y == -step)
        {
            x--;
            step++;
        }
        else if (x == -step)
        {
            if (y == step)
                x++;
            else
                y++;
        }
        else if (y == step)
        {
            if (x == step)
                y--;
            else
                x++;
        }
        else if (x == step)
        {
            if (y == -step)
                x--;
            else
                y--;
        }
        else
            x--;
        return *this;
    }

    bool operator==(const point &rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }

    bool operator!=(const point &rhs) const
    {
        return !(*this == rhs);
    }

    friend istream &operator>>(istream &in, point &p)
    {
        cin >> p.x >> p.y;
        p.step = max(abs(p.x), abs(p.y));
        return in;
    }
};

long long sumToBegin(long long n)
{
    return 4 * n * n + 4 * n;
}

int main()
{
    point target{};
    cin >> target;
    int base = max(abs(target.x), abs(target.y)) - 1;
    point current{-base, -base};
    long long step = sumToBegin(base);

    while (current != target)
    {
        step++;
        ++current;
    }
    cout << step << endl;
    return 0;
}