#include<stdio.h>
#include<string.h>
void main(){
    char str[100];
    printf("Enter your char of string to check the length :\n");
    scanf("%[^\n]s",str);
    printf("%s\n",str);
    int lenght=0;
    lenght=strlen(str);
    printf("Lenth of the string:\t%d",lenght);

    
}