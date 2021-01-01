#include <iostream>
#include <vector>

using namespace std;

vector<int> covered;
vector<int> keys;
vector<int> all_input;

void add_covered(int n){
    do
    {
        n = (n % 2 == 0) ? n / 2 : (3 * n + 1) / 2;
        covered.push_back(n);
    }
    while (n!=1);
}

bool is_covered(int n)
{
    for (int i = 0; i < covered.size(); i++)
    {
        if(covered[i] == n)
            return true;
    }
    return false;
}

void get_input()
{
    int count;
    cin >> count;
    for (int i = 0; i < count;i++)
    {
        int n;
        cin >> n;
        all_input.push_back(n);
        add_covered(n);
    }
}

void get_keys()
{
    for (int i = 0; i < all_input.size();i++){
        if(!is_covered(all_input[i]))
            keys.push_back(all_input[i]);
    }
}

void sort_keys()
{
    int tmp;
    int size = keys.size();

    for(int i=0;i<size-1;i++){
        for(int j = i+1;j<size;j++){
            if(keys[i] <  keys[j]){
                tmp = keys[i];
                keys[i] = keys[j];
                keys[j] = tmp;
            }
        }
    }
}

void put_keys()
{
    cout << keys[0];
    for (int i = 1; i < keys.size();i++)
        cout << " " << keys[i];
}

int main()
{
    get_input();
    get_keys();
    sort_keys();
    put_keys();
}