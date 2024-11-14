#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct priority_queue_item{
    char item[20];
    int priority;
    struct priority_queue_item* next;
} priority_queue_item;

priority_queue_item* createnode(char* item, int priority){
    priority_queue_item* newnode = (priority_queue_item*)malloc(sizeof(priority_queue_item));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strncpy(newnode->item, item, 19);
    newnode->item[19]='\0';
    newnode->priority=priority;
    newnode->next=NULL;
    return newnode;
}

priority_queue_item* delete(priority_queue_item* head, char* deletedData) {
    if (head == NULL) {
        deletedData[0]='\0';
        return NULL;
    }
    priority_queue_item* temp = head;
    strncpy(deletedData, temp->item, 19);
    deletedData[19]='\0';
    head = head->next;
    free(temp);
    return head;
}

priority_queue_item* insertnode(priority_queue_item** head,char* item, int priority){
    priority_queue_item* newnode = createnode(item, priority);
    if(newnode == NULL){
        return *head;
    }
    if(*head ==NULL || priority<(*head)->priority ){
        newnode->next=*head;
        *head=newnode;
    }
    else{
        priority_queue_item* current=*head;
        while(current->next !=NULL && priority>=current->next->priority){
            current=current->next;
        }
        newnode->next=current->next;
        current->next=newnode;
    }
    return *head;
}

void displayPriorityQueue(priority_queue_item* head) {
    priority_queue_item* current = head;
    while (current != NULL) {
        printf("Item: %s, Priority: %d\n", current->item, current->priority);
        current = current->next;
    }
}

int main(){
    priority_queue_item* head = NULL;

    head = insertnode(&head, "Item 7", 1);
    head = insertnode(&head, "Item 23", 3);
    head = insertnode(&head, "Item 36", 2);
    displayPriorityQueue(head);

    char deletedData[20];
    head = delete(head, deletedData);
    printf("popped %s\n", deletedData);

    displayPriorityQueue(head);
    return 0;
}