#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct long_number
{
    int data;
    struct long_number *next;

};

struct long_number* createNode(int data) {
    struct long_number* newNode = (struct long_number*)malloc(sizeof(struct long_number));
    if(!newNode) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct long_number* addLinkedLists(struct long_number* num1, struct long_number* num2) {
    struct long_number* result = NULL;
    struct long_number* temp, *prev = NULL;
    int carry = 0, sum;
    while(num1 != NULL || num2 != NULL ){
        sum=carry+ (num1 ? num1->data:0)+(num2 ? num2->data :0);
        carry=(sum>=10) ? 1:0;
        sum=sum % 10;

        temp=createNode(sum);

        if(result==NULL){
            result=temp;
        }
        else{
            prev->next=temp;
        }
        prev=temp;
        if(num1) num1=num1->next;
        if(num2) num2=num2->next;

    }
    if(carry>0){
        temp->next=createNode(carry);
    }
    return result;

}

void printList(struct long_number* node) {
    while (node != NULL) {
        printf("%d", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct long_number** head_ref, int new_data) {
    struct long_number* new_node = createNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    struct long_number* num1 = NULL;
    struct long_number* num2 = NULL;

    push(&num1, 7);
    push(&num1, 6);
    push(&num1, 3);
    push(&num1, 4);
    push(&num1, 5);

    push(&num2, 5);
    push(&num2, 3);
    push(&num2, 1);
    push(&num2, 8);
    push(&num2, 4);

    struct long_number* result = addLinkedLists(num1, num2);

    printf("Result: ");
    printList(result);

    return 0;
}