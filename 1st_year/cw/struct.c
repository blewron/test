#include<stdio.h>
#include<string.h>
struct stdudent
{
  int collegecode;
  float rollno;
  float percentage;
  char name[10];
};
void main(){
    struct stdudent s;
    printf("Enter the College code:");
    scanf("%d",&s.collegecode);
    printf("\nEnter the Roll number of student:");
    scanf("%f",&s.rollno);
        printf("\nEnter the total marks of student:");
        scanf("%f",&s.percentage);
        printf("\nEnter the Name of Student:\n");
        fgets(s.name,10,stdin);
        
}


