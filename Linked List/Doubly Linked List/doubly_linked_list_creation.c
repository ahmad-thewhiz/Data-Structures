#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node* insertion(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;


    if(head==NULL) {
        head = newNode;
    }
    else {
        struct node *curr=head;
        while(curr->next!=NULL)
            curr=curr->next;
        curr->next=newNode;
        newNode->prev=curr;
    }
    return head;
}

void display(struct node* head) {
    while(head!=NULL) {
        printf("%d",head->data);
        if(head->next!=NULL)
            printf("<->");
        head=head->next;
    }
}

int main() {
    struct node* head=NULL;
    int size;
    scanf("%d",&size);
    for(int i=0;i<size;i++) {
        int val;
        scanf("%d",&val);
        head=insertion(head, val);
    }
    printf("\nLinked List: ");
    display(head);
    return 0;
}