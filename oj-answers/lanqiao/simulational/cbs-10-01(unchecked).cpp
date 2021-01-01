#include <iostream>

using namespace std;

int main()
{
    int n,prev,cur;
    cin >> n;

    cin >> cur;
    prev = cur;
    cout << cur << " ";

    for (int i = 1; i < n; i++){
        cin >> cur;
        if(cur==-1){
            break;
        }
        if(cur != prev){
            cout << cur << " ";
            prev = cur;
        }
        
    }
        return 0;
}