#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>

#define SPLITER ','
using namespace std;

vector<string> &str_split(string s,int c, vector<string> &splited)
{
    splited.clear();
    int pos = 0;
    while((pos=s.find(c)) != -1)
    {
        splited.push_back(s.substr(0, pos));
        // cout << s.substr(0, pos) << endl;
        s = s.substr(pos + 1, s.size());
    }
    splited.push_back(s);
    // cout << s.substr(0, pos) << endl;
    return splited;
}

int countOfContinue(string &s)
{
    vector<string> ss{};
    str_split(s, ',',ss);

    int size = ss.size();
    int *vals = new int[size];
    for (int i = 0; i < size;i++)
    {
        vals[i] = atoi(ss[i].c_str());
    }
    sort(vals, vals + size, [](int a, int b) { return a <= b; });
    // for (int i = 0; i < size;i++){
    //     cout << vals[i] << endl;
    // }
    int cont_cur = 1;
    int cont_max = 1;
    for (int i = 1; i < size;i++)
    {
        if(vals[i] == vals[i-1] + 1){
            cont_cur++;
        }else{
            if(cont_max < cont_cur){
                cont_max = cont_cur;
            }
            cont_cur = 1;
        }
    }
    if(cont_max < cont_cur){
        cont_max = cont_cur;
    }
    return cont_max;
}

int main()
{
    string s{};
    while(cin >> s){
        cout << countOfContinue(s) << endl;
    }
    return 0;
}