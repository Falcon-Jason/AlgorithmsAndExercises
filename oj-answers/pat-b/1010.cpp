#include <stdio.h>

int main() {
    int c,e;

    int i=0;
    bool empty=true;
    while(scanf("%d%d",&c,&e) == 2){
        if(e>0){
            if(empty){
                printf("%d %d",c*e,e-1);
                empty = false;
            }else{
                printf(" %d %d",c*e,e-1);
            }
        }
        if(empty){
            printf("0 0");
        }
    }
}