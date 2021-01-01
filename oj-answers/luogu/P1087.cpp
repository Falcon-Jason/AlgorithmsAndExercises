#include <cstdio>
#include <cctype>

#define MAX_S 10
const int pow[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

void put_type(int *ls, int size)
{
    int first = *ls;
    for (int i = 0; i < size;i++)
    {
        if(ls[i] != first){
            putchar('F');
            return;
        }
    }
    putchar(first-'0' ? 'I' : 'B');
}

void postFibTree(int *ls, int size)
{
    if(size == 0)
    {
        return;
    }
    postFibTree(ls, size / 2);
    postFibTree(ls + size / 2, size / 2);
    put_type(ls, size);
}

void skip_space()
{
    int c;
    while(isspace(c=getchar()))
        ;
    ungetc(c, stdin);
}

int main()
{
    int size;
    int *arr;
    scanf("%d", &size);
    skip_space();
    size = (size >= 0 && size <= MAX_S) ? pow[size] : pow[MAX_S];
    arr = new int[size];
    
    for (int i = 0; i < size;i++){
        arr[i] = getchar();
    }

    postFibTree(arr, size);
    return 0;
}

// Accepted: https://www.luogu.org/recordnew/show/16636004