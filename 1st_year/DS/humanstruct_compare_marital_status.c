#include<stdio.h>
#include<string.h>

typedef enum{
    single,
    married,
    widowed,
    divorced,
}marital_status;

typedef union{
    struct{
        char marriage_date[11];

    }married;
    struct{
        char marriage_date[11];
        char death_of_partner_date[11];
    }widowed;
    struct{
        char divorce_date[11];
    }divorced;
}marital_info;


struct human_being
{
    int age;
    char name[10];
    float salary;
    marital_status status;
    marital_info info;
}p[2];

void comparestruct(){
    if(strcmp(p[0].name, p[1].name) ==0 && p[0].age==p[1].age && p[0].salary==p[1].salary){
        printf("\nYes, both the humans are same .\n");

    }
    else {
        printf("\nNo, they are not same.\n");
    }
}
void value_for_marital_status( marital_status status){
    for(int i=0;i<2;i++){
        switch (p[i].status) {
            case married:
                printf("\nEnter the marriage date(in YYYY:MM:DD format) :\n");
                scanf("%s", &p[i].info.married.marriage_date);
                break;
            case widowed:
                printf("\nEnter the marriage date(in YYYY:MM:DD format) :\n");
                scanf("%s", &p[i].info.widowed.marriage_date);
                printf("Enter the death of partner date(in YYYY:MM:DD format) :\n");
                scanf("%s", &p[i].info.widowed.death_of_partner_date);
                break;
            case divorced:
                printf("Enter the divorced date(in YYYY:MM:DD format) :\n");
                scanf("%s", &p[i].info.divorced.divorce_date);
                break;
            default:
                    break;
        }
    }
}

void main(){
    struct human_being;
    for(int i=0;i<2;i++){

    
    printf("Enter the name of human being:\n");
    scanf("%s", p[i].name);
    printf("\nEnter the age of human being:\n");
    scanf("%d", &p[i].age);
    printf("\nEnter the salary of human being:\n");
    scanf("%f", &p[i].salary);
    }
    // comparestruct();
    comparestruct();
    printf("\nEnter the marital status of the human being (answer in integer from 1 to 4):\n");
    printf("\t1. Single\n\t2. Married\n\t3. Widowed\n\t4. Divorced\n");
    for(int i=0;i<2;i++){
    scanf("%d",&p[i].status);
    }
    for(int i=0;i<2;i++){
    value_for_marital_status( p[i].status);
    }
    for(int i=0;i<2;i++){
        printf("\nName:%s\nAge:%d\nSalary:%f\nMarital status:%d\n");
        if(p[i].status==2){
            printf("Marriage Date: %s\n", p[i].info.married.marriage_date);
        }
        else if(p[i].status==3){
            printf("Death of partner Date: %s\n Marriage Date: %s",p[i].info.widowed.death_of_partner_date,p[i].info.widowed.marriage_date);
        }

        else if (p[i].status==4)
        {
            printf("Divorce Date: %s\n", p[i].info.divorced.divorce_date);

        }
    }
}
