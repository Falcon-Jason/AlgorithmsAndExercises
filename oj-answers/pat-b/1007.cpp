#include <iostream>
#include <math.h>

using namespace std;
bool is_prime(int n){
    if(n<0)
        return false;

    for (int i = 2; i < (int)sqrt(n) + 1;i++){
        if(n%i == 0)
            return false;
    }

    return true;
}

int main(){
    int count_of_n = 0;
    int pre_prime = 2;
    int post_prime = 2;
    int n;
    cin >> n;

    for(int i=3;i<=n;i++){
        if(is_prime(i)){
            pre_prime = post_prime;
            post_prime = i;

            if(post_prime-pre_prime == 2) 
                count_of_n++;
        }
    }
    cout << count_of_n;
}