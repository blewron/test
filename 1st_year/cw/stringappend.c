#include <stdio.h>
#include <string.h>
#define max 100

int main()
{
    char str1[max], str2[max];
    printf("Enter the first string: ");
    gets(str1);
    printf("Enter the second string: ");
    gets(str2);

    // Remove the trailing newline character from str1 and str2
    // str1[strcspn(str1, "\n")] = '\0';
    // str2[strcspn(str2, "\n")] = '\0';

    // Concatenate the two strings into str3
    strcat(str1,str2);

    // Print the concatenated string with a newline
    printf("%s\n", str1);

    return 0;
}
