#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

int size=0;
struct node *head, *tail=NULL;

void addNode(int data) {
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    if(head==NULL) {
        head=tail=newNode;
        head->prev=NULL;
        tail->next=NULL;
    }
    else {
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
        tail->next=NULL;
    }
    size++;
}

void addMid(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    if(head==NULL) {
        head=tail=newNode;
        head->prev=NULL;
        tail->next=NULL;
    }
    else {
        struct node *curr=head, *temp=NULL;
        int mid;
        if(size%2==0)
        mid=size/2;
        else
        mid=size/2+1;
        for(int i=1;i<mid;i++) {
            curr=curr->next;
        }
        temp=curr->next;
        temp->prev=curr;
        curr->next=newNode;
        newNode->prev=curr;
        newNode->next=temp;
        temp->prev=newNode;
    }
    size++;
}

void display() {
    struct node *curr=head;
    if(head==NULL) {
        printf("Empty List");
        return ;
    }
    while(curr!=NULL) {
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}

int main() {
    int i,n,n1,ele,ele1;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&ele);
        addNode(ele);
    }
    display();
    scanf("%d",&n1);
    for(i=0;i<n1;i++) {
        scanf("%d",&ele1);
        addMid(ele1);
        display();
    }
    return 0;
}
