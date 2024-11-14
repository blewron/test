#include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
 struct node{
 int data;
 struct node *add;
 }*head;
 void selection(){
 struct node*p=head;
 struct node*q=head->add;
 int n=0;
 while(p!=NULL){
 n++;
 p=p->add;
 }
 p=head;
 for(int i=0;i<n-1;i++){
 for(int j=i+1;j<n;j++){
 if((p->data)>(q->data)){
 int a=p->data;
 p->data=q->data;
 q->data=a;
 }
 q=q->add;
 }
 p=p->add;
 q=p->add;
 }
}
 int main(){
 time_t currentTime;
 struct tm *localTime;
 time(&currentTime);
 localTime = localtime(&currentTime);
 // Display the current time and date
 printf("Current Time and Date: %s", asctime(localTime));
 struct node* one=(struct node*)malloc(sizeof(struct node));
 struct node* two=(struct node*)malloc(sizeof(struct node));
 struct node* three=(struct node*)malloc(sizeof(struct node));
 struct node* four=(struct node*)malloc(sizeof(struct node));
 struct node* five=(struct node*)malloc(sizeof(struct node));
 struct node* six=(struct node*)malloc(sizeof(struct node));
 head=one;
 one->add=two;
 two->add=three;
 three->add=four;
 four->add=five;
 five->add=six;
 six->add=NULL;
 one->data=152;
 two->data=94;
 three->data=5554;
 four->data=223;
 five->data=51;
 six->data=206;
 struct node *temp=head;
 while(temp!=NULL){
 printf("%d \t",temp->data);
 temp=temp->add;
 }
 printf("\n");
 selection();
temp=head;
 while(temp!=NULL){
 printf("%d \t",temp->data);
 temp=temp->add;
 }
 return 0;
 }