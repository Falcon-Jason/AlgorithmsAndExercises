#include <stdio.h>
#include <string.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define MAXSIZE 128

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

int programming(const int *arr, int size)
{
    dpArr[0] = max(arr[0],0);

	for(int i=1;i<size;i++)
	{
		dpArr[i] = max(dpArr[i-1] + arr[i], arr[i]);
	}

	int max = dpArr[0];
	for(int i = 1; i<size; i++)
	{
		if(dpArr[i] > max)
		{
			max = dpArr[i];
		}
	}
	return max;
}

int maxSubsquenceSum(const int *arr, int size, int *subsq, int *subsize)
{
	int sum = programming(arr, size);

	int maxi = 0;
	for(int i = 1; i<size; i++)
	{
		if(dpArr[i] > dpArr[maxi])
		{
			maxi = i;
		}
	}

	int lo = maxi;
	while (lo > 0 && dpArr[--lo] > 0)
		;
	
	lo++;
	*subsize = 0;
	for(int i = lo; i <= maxi; i++)
	{
		subsq[(*subsize)++] = arr[i];
	}
	
	return sum;
}

int main(void)
{
	int arr[MAXSIZE];
	int subsq[MAXSIZE];
	int subsize;
	int count = readArr(arr,MAXSIZE);
	int sum = maxSubsquenceSum(arr,count,subsq,&subsize);
	printf("%d\n",sum);
	printArr(subsq,subsize);
	return 0;
}
