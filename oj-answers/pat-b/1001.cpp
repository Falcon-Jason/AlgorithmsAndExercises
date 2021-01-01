#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int i,n;
    i = 0;
    cin >> n;

    for(i = 0;n!=1;i++){
        if(n%2==0){
            n/=2;
        }else{
            n = (3 * n + 1) / 2;
        }
    }

    cout << i;
    return 0;
}
