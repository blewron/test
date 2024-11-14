#include<stdio.h>

struct product{
    int id;
    char name[10];
    float price;

}p[5];
void main(){
 int i;
 printf("Enter the details of 5 products:\n");
 for(i=0;i<=4;i++){
    scanf("%d %s %f",&p[i].id, p[i].name, &p[i].price);
    printf("\n");
    }
    printf("The entered data of products are as follows: \n");
    printf("\nID\tNAME\tPRICE");
    for (int i = 0; i <=4; i++)
    {
        printf("\n%d\t%s\t%.2f",p[i].id, p[i].name, p[i].price);
        
    }
    


}