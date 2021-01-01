#include <stdio.h>

#define MAX_SIZE 1024

int size[5] = {0};
int data[5][MAX_SIZE] = {{0}};
int answer[5] = {0};

void ReadData();
void PrintAnswer();

int main()
{
    ReadData();
    PrintAnswer();
}

void ReadData()
{
    int n;
    scanf("%d", &n);
    int val;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        int part = val % 5;
        data[part][size[part]++] = val;
    }
}

int A0();
int A1();
int A2();
double A3();
int A4();

void PrintAnswer()
{
    if(A0() == 0)
        printf("N");
    else
        printf("%d", A0());

    if(size[1] == 0)
        printf(" N");
    else
        printf(" %d", A1());
    
    if(size[2] == 0)
        printf(" N");
    else
        printf(" %d", A2());
    
    if(size[3] == 0)
        printf(" N");
    else
        printf(" %.1f", A3());

    if(size[4] == 0)
        printf(" N");
    else
        printf(" %d", A4());

    putchar('\n');
}

int A0()
{
    int sum = 0;
    for (int i = 0; i < size[0];i++)
    {
        sum += (data[0][i] & 1) ? 0 : data[0][i];
    }
    return sum;
}

int A1()
{
    int sum = 0;
    for (int i = 0; i < size[1];i++)
    {
        sum += (i & 1) ? -data[1][i] : data[1][i];
    }
    return sum;
}

int A2()
{
    return size[2];
}

double A3()
{
    int sum = 0;
    for (int i = 0; i < size[3];i++)
    {
        sum += data[3][i];
    }
    return (double)sum/size[3];
}
int A4()
{
    int max = 0;
    for (int i = 0; i < size[4];i++)
    {
        max = max > data[4][i] ? max : data[4][i];
    }
    return max;
}