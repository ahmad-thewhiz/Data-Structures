#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

void insert_node(struct node **head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    
    if(*head==NULL) {
        newNode->prev=NULL;
        *head=newNode;
        return;
    }
    struct node* lastNode = *head;
    while(lastNode->next!=NULL) {
    lastNode=lastNode->next;
    }
    lastNode->next=newNode;
    newNode->prev=lastNode;
}

void delete_node(struct node **head, int pos) {
    if(*head==NULL) {
        return ;
    }
    struct node *curr=*head;
    if(pos==1) {
        *head=curr->next;
        
        if(*head!=NULL) {
        (*head)->prev=NULL;
        }
        free(curr);
        return ;
    }
    
    for(int i=1;curr!=NULL&&i<pos;i++) {
    curr=curr->next;
    }
    if(curr==NULL) {
        return ;
    }
    
    curr->prev->next=curr->next;
    if(curr->next!=NULL) {
    curr->next->prev=curr->prev;
}
free(curr);
}

void print_list(struct node* head) {
    while(head!=NULL) {
        printf("%d ",head->data);
        head=head->next;
    }
}

int main() {
    struct node *head = NULL;
    int n,val,pos;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&val);
        insert_node(&head,val);
    }
    scanf("%d",&pos);
    delete_node(&head,pos);
    print_list(head);
    return 0;
}