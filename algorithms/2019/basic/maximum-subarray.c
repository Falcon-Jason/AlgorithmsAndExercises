#include <stdio.h>

int max_subsquence_sum(const int *sq,int len)
{
    int cur_sum = 0;
    int max_sum = 0;

    for(int i = 0; i<len;i++)
    {
        cur_sum += sq[i];
        if(cur_sum > max_sum)
            max_sum = cur_sum;
        else if(cur_sum < 0)
            cur_sum = 0;
    }

    return max_sum;
}

int main(int argc, char const *argv[])
{
    int total;
    printf("total:");
    scanf("%d",&total);
    int ls[total];
    printf("list:");
    for(int i =0;i<total;i++)
        scanf("%d\n",&ls[i]);

    printf("The max subsquence sum is: %d",max_subsquence_sum(ls,total));
    return 0;
}