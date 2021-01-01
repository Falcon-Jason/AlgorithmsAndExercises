#include <iostream>

using namespace std;

bool deep_judge(int a, int b, int c);
bool judge(string str);

int main(int argc, char const *argv[])
{
    int line;
    cin >> line;
    for(int i=0;i<line;i++){
        char c_str[101];
        
        cin >> c_str;

        string str{c_str};
        printf("%s\n",judge(str)?"YES":"NO");
    }    
    return 0;
}

bool deep_judge(int a,int b, int c)
{
    if(a < 0 || b <= 0 || c < 0){
        return false;
    }

    if(b==1){
        if(a==c) return true;
        else return false;
    }

    return deep_judge(a, b-1, c-a);
}

bool judge(string str)
{
    int a=0,b=0,c=0;
    int *p = &a;

    for(int i=0;str[i] != '\0'; i++){
        if(str[i] == 'A') (*p)++;
        else if(str[i] == 'P' && p==&a) p = &b;
        else if(str[i] == 'T' && p==&b) p = &c;
        else return false;
    }
    if(p != &c) return false;
    return deep_judge(a,b,c);
}