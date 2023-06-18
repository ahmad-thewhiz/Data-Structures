#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* create_node(node* head, int val) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=val;
    newNode->next=NULL;
    
    if(!head) 
        return newNode;
    else if(val<=head->data) {
        newNode->next=head;
        head=newNode;
        return head;
    }
    else {
        node* temp=head;
        while(temp->next && temp->next->data<val) 
            temp=temp->next;
        newNode->next=temp->next;
        temp->next=newNode;
    }
    return head;
}

int pop_node(node** head) {
    int x=-1;
    node* temp=(*head);
    if(!*head) {
        printf("Queue Underflow\n");
        return x;
    }
    x=(*head)->data;
    *head=(*head)->next;
    free(temp);
    return x;
}

void display(node* head) {
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
}

int main() {
    node* head=NULL;
    int n;
    printf("Enter number of elements to be stored in the priority queue: ");
    scanf("%d",&n);
    printf("\nEnter Elements: ");
    for(int i=0;i<n;i++) {
        int val;
        scanf("%d",&val);
        head=create_node(head, val);
    }
    printf("\nPriority Queue: ");
    display(head);
    int ch;
    do {
        int ele;
        printf("\nEnter -1 to avoid poping elements: ");
        scanf("%d",&ch);
        if(ch!=-1)
        ele=pop_node(&head);
        printf("\nPopped Element: %d",ele);
    } while(ch!=-1);
    return 0;
}