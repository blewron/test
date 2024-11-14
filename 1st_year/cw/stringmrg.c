#include<stdio.h>
#include<string.h>
void main (){
    char str1[100],str2[100];
    printf("Enter the char of first string :\n");
    scanf("%s",str1);
    printf("Enter the char of second string:\n");
    scanf("%s",str2);
    char* ptr=str1;
    while(*ptr!='\0'){
        printf("%c",*ptr);
        ptr++;
    }
    while(*ptr=='\0'){
        char* ptr=str2;
        printf("%c",*ptr);

        

    }
}

