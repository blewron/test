#include<stdio.h>
#define max 100
void main(){
    char str[max];
    printf("Enter your char of string:\n");
    fgets(str,max, stdin);
    printf("your string is:\n ");
    puts(str);
}