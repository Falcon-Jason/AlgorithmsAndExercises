#include <cstdio>
#include <cctype>
#include <cstring>

#define MAX_N 256
#define SNAKE 0
#define CAMEL 1

int checkstyle(char *varname){
    for (int i = 0; varname[i] != '\0'; i++){
        if(varname[i]=='_')
            return SNAKE;
        else if(isupper(varname[i]))
            return CAMEL;
    }

    return -1;
}

void tocamel(char *varname){
    char tmp[MAX_N];
    int i, j;
    for (i = 0, j = 0; varname[i] != '\0'; i++,j++)
    {
        if(varname[i] == '_'){
                tmp[j] = toupper(varname[++i]);
        }
        else{
            tmp[j] = varname[i];
        }
    }
    tmp[j] = '\0';

    strcpy(varname, tmp);
}

void tosnack(char *varname){
    char tmp[MAX_N];
    int i, j;
    for (i = 0, j = 0; varname[i] != '\0'; i++,j++)
    {
        if(isupper(varname[i])){
            tmp[j++] = '_';
            tmp[j] = tolower(varname[i]);
        }
        else{
            tmp[j] = varname[i];
        }
    }
    tmp[j] = '\0';
    strcpy(varname, tmp);
}

char *convert(char *varname){
    
    switch (checkstyle(varname))
    {
        case SNAKE:
            tocamel(varname);
            break;
    
        case CAMEL:
            tosnack(varname);
            break;
    }

    return varname;
}


int main(){
    char varname[MAX_N];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n;i++){
        scanf("%s", varname);
        puts(convert(varname));
    }
    getchar();
    return 0;
}