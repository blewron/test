#include <stdio.h>
#include <stdlib.h>


struct student
{
int data;
struct student *addr;
};


void display(struct student *head)
{
int c1 = 1;
while (head != NULL)
{
printf("\ns%d data->%d\n", c1, head->data);
printf("s%d address->%p\n", c1, (void *)head->addr);
c1++;
head = head->addr;
}
}
 

void randmdeletion(struct student **head, int del)
{
struct student *temp = *head;
struct student *temp2 = NULL;
int count = 0;


if (del == 1)
{
*head = temp->addr;
free(temp);
return;
}


while (count != (del - 2))
{
temp = temp->addr;
count++;
}
temp2 = temp->addr;


temp->addr = temp->addr->addr;
free(temp2);
}


void randominsertion(struct student **head, int data, int pos)
{
struct student *temp = *head;
struct student *s5 = (struct student *)malloc(sizeof(struct student));
s5->data = data;
s5->addr = NULL;


if (pos == 1)
{
s5->addr = *head;
*head = s5;
return;
}


int count = 0;
while (count != (pos - 2))
{
if (temp == NULL)
{
printf("Invalid position\n");
return;
}
temp = temp->addr;
count++;
}
s5->addr = temp->addr;
temp->addr = s5;
}


void reverse(struct student **head)
{
struct student *prev = NULL;
struct student *current = *head;
struct student *next = NULL;


while (current != NULL)
{
next = current->addr;
current->addr = prev;
prev = current;
current = next;
}
*head = prev;
}


int main()
{
struct student *s1 = NULL, *s2 = NULL, *s3 = NULL, *s4 = NULL, *s5 = NULL, *head = NULL;


s1 = (struct student *)malloc(sizeof(struct student));
s2 = (struct student *)malloc(sizeof(struct student));
s3 = (struct student *)malloc(sizeof(struct student));
s4 = (struct student *)malloc(sizeof(struct student));
s5 = (struct student *)malloc(sizeof(struct student));


printf("\nEnter the data of students :\n");
printf("s1 :");
scanf("%d", &s1->data);
printf("s2 :");scanf("%d", &s2->data);
printf("s3 :");
scanf("%d", &s3->data);
printf("s4 :");
scanf("%d", &s4->data);


s1->addr = s2;
s2->addr = s3;
s3->addr = s4;
s4->addr = NULL;
head = s1;
struct student *temp;
temp = head;
struct student *temp2 = NULL;


printf("\nEnter 1->Insertion at first position\nEnter 2->Insertion at last position\nEnter 3->Insertion at random position\nEnter 4->No. of Traversal req in the list\nEnter 5->Delete an element at a random position from the link list\nEnter 6->Reverse the linked list");
int choice, pos, data;
printf("\n\nEnter your choice :");
scanf("%d", &choice);
int count = 0, del;


switch (choice)
{
case 1:
printf("\nEnter the data of s5 :");
scanf("%d", &data);
randominsertion(&head, data, 1);
display(head);
break;


case 2:
printf("\nEnter the data of s5 :");
scanf("%d", &data);
randominsertion(&head, data, 4); // Assuming insertion at last position
display(head);
break;


case 3:
printf("\nEnter the position that you want to insert the data :");
scanf("%d", &pos);
printf("\nEnter the data of s5 :");
scanf("%d", &data);
randominsertion(&head, data, pos);
display(head);
break;


case 4:
while (temp != NULL)
{
count++;
temp = temp->addr;
}
printf("\nThe no. of traversal req in the given linked list :%d", count);
break;


case 5:
printf("\nEnter the position you want to delete :");
scanf("%d", &del);
randmdeletion(&head, del);
display(head);
break;


case 6:
reverse(&head);
printf("\nReversed linked list:\n");
display(head);
break;
 

default:
printf("Invalid choice\n");
}


return 0;
}
