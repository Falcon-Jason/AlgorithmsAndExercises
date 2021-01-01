#include <cstdio>
int x[100000];
int y[100000];
int main(){

    int n;
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d%d", &x[i], &y[i]);
    }

    for (int i = 0; i < n;i++){
        for (int j = i + 1; j < n;j++){
            if(x[i]+x[j] == y[i]+y[j]){
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);
    return 0;
}