#include<stdio.h>
struct student{
    int roll;
    char name[10];
    float marks[5];
    float average;
}s;
void input(){
    printf("Enter your name :\n");
    scanf("%[^\n]s",s.name);
    printf("Enter your roll number:\n");
    scanf("%d",s.roll);
    printf("Enter your marks :\n");
    for (int i=0;i<5;i++){
        scanf("%f",&s.marks[i]);
    }

     }
     void calculate(){
        float sum=0;
        for(int i=0;i<5;i++){
            sum+=s.marks[i];
        }
        float avrage=0;
        avrage=sum/5;
        s.average=avrage;
     }
     void display(){
        printf("Name : %s\n",s.name);
        printf("roll : %d\n",s.roll);
        for(int i=0;i<5;i++){
            printf("marks : %f",s.marks[i]);
        }
        printf("%f",s.average);
     }
     void main(){
        input();
        display();
     }