#include <stdio.h>
#include <string.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define MAXSIZE 128

int dpArr[MAXSIZE][MAXSIZE];

int programming(const char *strA, const char *strB)
{
    int m = strlen(strA);
    int n = strlen(strB);

    for(int i = 0; i < m; i++)
    {
        dpArr[i][0] = 0;
    }
    for(int j = 0; j < n; j++)
    {
        dpArr[0][j] = 0;
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(strA[i - 1] == strB[j - 1])
            {
                dpArr[i][j] = dpArr[i - 1][j - 1] + 1;
            }
            else
            {
                dpArr[i][j] = max(dpArr[i][j - 1], dpArr[i - 1][j]);
            }
        }
    }
    return dpArr[m][n];
}

char* longestCommonSubsquence(char *subs, const char *strA, const char *strB)
{
    int i = strlen(strA);
    int j = strlen(strB);
    int k = programming(strA, strB);

    subs[k] = '\0';
    while(k>0)
    {
        if(dpArr[i][j] == dpArr[i-1][j])
        {
            i--;
        }
        else if(dpArr[i][j] == dpArr[i][j-1])
        {
            j--;
        }
        else
        {
            subs[--k] = strA[i-1];
            i--;
            j--;
        }
    }
    return subs;
}

int main()
{
    char a[MAXSIZE];
    char b[MAXSIZE];
    char common[MAXSIZE];

    fgets(a, MAXSIZE, stdin);
    fgets(b, MAXSIZE, stdin);

    longestCommonSubsquence(common,a,b);
    puts(common);
    return 0;
}