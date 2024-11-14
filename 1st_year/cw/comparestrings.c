#include <stdio.h>
#include <string.h>
int main()
{
    int i, j, k, flag = 1;
    char str1[100], str2[100];
    printf("Enter two strings: ");
    gets(str1);
    gets(str2);
    i = strlen(str1);
    j = strlen(str2);
    if (i > j)
    {
        printf("string 1 is greater.\n");
    }
    else if (i < j)
    {
        printf("String 2 is greater.\n");
    }
    else
    {
        for (int k = 0; k < i; k++)
        {
            if (str1[k] != str2[k])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            printf("Both are equal");
        }
        else
        {
            printf("Both are not equal");
        }
    }
}