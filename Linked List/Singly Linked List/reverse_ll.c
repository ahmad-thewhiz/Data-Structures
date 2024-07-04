#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

// void reverse(node* head, node* curr, node* prev) {
//     if(curr==NULL) {
//         head=prev;
//         return;
//     }

//     node* forward = curr->next;
//     reverse(head, forward, curr);
//     curr->next=prev;
// }

node* insert_node(node* head, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) 
        head = newNode;
    else {
        node* curr = head;
        while (curr->next != NULL) 
            curr = curr->next;
        curr->next = newNode;
    }
    return head;
}

node* reverse_ll(node* head) {
    node* prev=NULL;
    node* curr=head;
    node* next=NULL;

    if(head==NULL)
        return NULL;

    while(curr!=NULL) {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head = prev;
    return head;
}

void display(node* head) {
    while(head!=NULL) {
        printf("%d",head->data);
        if(head->next!=NULL)
            printf("->");
        head=head->next;
    }
}

int main() {
    node* head=NULL;
    int size;
    scanf("%d",&size);
    for(int i=0;i<size;i++) {
        int val;
        scanf("%d",&val);
        head=insert_node(head, val);
    }
    printf("Before Reverse: ");
    display(head);
    head=reverse_ll(head);
    printf("\nAfter Reverse: ");
    display(head);
    return 0;
}
