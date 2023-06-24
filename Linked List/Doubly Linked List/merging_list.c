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


struct node* merger(struct node* head1, struct node* head2) {
    if(head1==NULL || head2==NULL)
        return;
    
    struct node* mergedList=NULL;
    struct node* tail=NULL;

    if(head1->data<=head2->data) {
        mergedList=head1;
        tail=head1;
        head1=head1->next;
    }
    else {
        mergedList = head2;
        tail=head2;
        head2=head2->next;
    }

    while(head1!=NULL && head2!=NULL) {
        if(head1->data <= head2->data) {
            tail->next=head1;
            tail=head1;
            head1=head1->next;
        }
        else {
            tail->next=head2;
            tail=head2;
            head2=head2->next;
        }
    }

    if(head1!=NULL)
        tail->next=head1;
    else if(head2!=NULL)
        tail->next=head2;

    return mergedList;
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
    struct node* head1=NULL;
    struct node* head2=NULL;
    struct node* newList=NULL;
    int size1,size2;
    printf("Enter First LinkedList\n");
    scanf("%d",&size1);
    for(int i=0;i<size1;i++) {
        int val;
        scanf("%d",&val);
        head1=insertion(head1, val);
    }
    printf("Enter Second LinkedList\n");
    scanf("%d",&size2);
    for(int i=0;i<size2;i++) {
        int val;
        scanf("%d",&val);
        head2=insertion(head2, val);
    }
    printf("\nMerged Linked List: ");
    newList = merger(head1, head2);
    display(newList);
    return 0;
}