#include <stdio.h>
#define MAXSIZE 128

#define max(a,b) ((a) > (b) ? (a) : (b))
int dpArr[MAXSIZE];

int readArr(int *arr, int maxsize)
{
    int i = 0;
    while(i < maxsize - 2 && scanf("%d",&arr[i++]) == 1)
		;
    return --i;
}

void printArr(const int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int programming(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        dpArr[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j])
            {
                dpArr[i] = max(dpArr[i], dpArr[j] + 1);
            }
        }
    }

    int ret = dpArr[0];
    for(int i = 0; i < size; i++)
    {
        ret = dpArr[i] > ret ? dpArr[i] : ret;
    }

    return ret;
}

int longestIncreasingSubsquence(int *arr, int size, int *subsq)
{
    int maxLength = programming(arr,size);
    int maxdp = 1;
    int subi = 1;
    subsq[0] = arr[0];
    for(int i = 1; i <= size; i++)
    {
        if(dpArr[i] > maxdp)
        {         
            subsq[subi++] = arr[i];
            maxdp = dpArr[i];
        }
    }
    return maxLength;
}

int main()
{
    int arr[MAXSIZE];
    int subsq[MAXSIZE];

	int count = readArr(arr,MAXSIZE);
    int subsqLength = longestIncreasingSubsquence(arr,count,subsq);

    printf("%d\n",subsqLength);
    printArr(subsq,subsqLength);
    
    return 0;
}