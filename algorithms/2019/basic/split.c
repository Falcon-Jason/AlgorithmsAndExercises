#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define new_array(T, s) calloc((s), sizeof(T))

// 截取字符串str[begin..end), 产生一个新的字符串
char *substr(const char *str, int begin, int end)
{
    char *subs = new_array(char, end - begin + 1);
    strncpy(subs, str + begin, end - begin);
    subs[end - begin] = '\0';
    return subs;
}

// 将字符串text按空白符拆分为最多max_result_size个子字符串，结果保存在result中，返回实际拆分的子字符串个数。
int split(const char *text, char **result, int max_result_size)
{
    int size = 0;
    int in_word = 0;
    int i, begin;

    for (begin = i = 0; text[i] != '\0'; i++)
    {

        if (!in_word && !isspace(text[i]))
        {
            in_word = 1;
            begin = i;
        }
        else if (in_word && isspace(text[i]))
        {
            in_word = 0;
            // 若子字符串个数达到上限，将剩余信息全部保存在最后一个子字符串中并退出
            if (size == max_result_size - 1)
            {
                result[size++] = substr(text, begin, strlen(text));
                in_word = 0;
                break;
            }
            result[size++] = substr(text, begin, i);
        }
    }
    // 确保最后一个子字符串能够被保存
    if (i != begin && in_word)
    {
        result[size++] = substr(text, begin, i);
    }
    return size;
}

// 测试
int main()
{
    char *splited[10];
    int count;

    char str1[] = "A quick brown fox jumped over a lazy dog";
    printf("%s\n", str1);
    count = split(str1, splited, 10);
    for (int i = 0; i < count; i++)
    {
        printf("%s|\n", splited[i]);
        free(splited[i]);
    }
    
    char str2[] = "  A quick brown fox jumped over a lazy dog  ";
    printf("%s\n", str2);
    count = split(str2, splited, 10);
    for (int i = 0; i < count; i++)
    {
        printf("%s|\n", splited[i]);
        free(splited[i]);
    }

    char str3[] = "  A quick  brown  fox \t jumped over a  lazy dog  \n";
    printf("%s\n", str3);
    count = split(str3, splited, 10);
    for (int i = 0; i < count; i++)
    {
        printf("%s|\n", splited[i]);
        free(splited[i]);
    }

    char str4[] = "A quick brown fox jumped over a lazy dog";
    printf("%s\n", str4);
    count = split(str4, splited, 5);
    for (int i = 0; i < count; i++)
    {
        printf("%s|\n", splited[i]);
        free(splited[i]);
    }

    return 0;
}