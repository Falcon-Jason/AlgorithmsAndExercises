#include <iostream>
#include <vector>

using namespace std;
class BalancedQuickUnionSet
{
  private:
    vector<int> contactors;
    vector<int> weights;
    int countOfSet;

    int find(int p)
    {
        while (p != contactors[p])
        {
            p = contactors[p];
        }
        return p;
    }

  public:
    BalancedQuickUnionSet(int size)
    {
        countOfSet = size;
        for (int i = 0; i < size; i++)
        {
            contactors.push_back(i);
            weights.push_back(1);
        }
    }

    bool isConnected(int p, int q)
    {
        return find(p) == find(q);
    }

    void connect(int p, int q)
    {
        int i = find(p);
        int j = find(q);

        if (i == j)
        {
            return;
        }

        if (weights[i] < weights[j])
        {
            contactors[i] = j;
            weights[j] += weights[i];
        }
        else
        {
            contactors[j] = i;
            weights[i] += weights[j];
        }

        countOfSet--;
    }

    int getCountOfSet()
    {
        return countOfSet;
    }
};

int main(void)
{
    int x, y;
    // int size;
    int connects;
    cin >> x >> y >> connects;

    BalancedQuickUnionSet set(x * y + 1);
    for (int i = 0; i < connects; i++)
    {
        int m, n;
        cin >> m >> n;
        set.connect(m, n);
    }
    cout << set.getCountOfSet() - 1;
    return 0;
}
// accepted: http://lx.lanqiao.cn/detail.page?submitid=3713823