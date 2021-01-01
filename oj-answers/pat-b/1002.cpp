#include <iostream>
using namespace std;

const char *name_of_num(int);

int main(int argc, char const *argv[])
{
    int sum = 0;
    char dig;
    for(dig = cin.get(); dig!='\n'; dig=cin.get()){
        sum += dig-'0';
    }
    int num[100];
    int i;
    for(i = 0;sum;i++){
        num[i] = sum % 10;
        sum /= 10;
    }

    while(--i>=0){
        cout << name_of_num(num[i]);
        if(i!=0) cout << ' ';
    }
    return 0;
}

const char *name_of_num(int dig)
{
    switch(dig){
        case 0:
        return "ling";
        
        case 1:
        return "yi";
        
        case 2:
        return "er";
        
        case 3:
        return "san";
        
        case 4:
        return "si";
        
        case 5:
        return "wu";

        case 6:
        return "liu";

        case 7:
        return "qi";

        case 8:
        return "ba";

        case 9:
        return "jiu";
    }
    return nullptr;
}
