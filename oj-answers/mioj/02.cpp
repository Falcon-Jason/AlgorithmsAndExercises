#include <cstdio>
#include <cstring>

int main()
{
    int arr[512];
    int val;
    memset(arr,0,512);
    while(scanf("%d",&val) == 1){
        arr[val]++;
    }
    for(int i=0;i<512;i++){
        if(arr[i] == 1){
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}

