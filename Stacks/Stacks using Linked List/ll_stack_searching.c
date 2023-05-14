#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top=NULL;

void push(int no) {
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=no;
    newnode->next=top;
    top=newnode;
}

void pop(int ele) {
    int flag=0;
    struct node *temp=top;
    while(temp!=NULL) {
        if(temp->data==ele) {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==1) {
        printf("Element found");
    }
    else if(flag==0){ 
    printf("Element not found");
    }
}

int main() {
    int i=1;
    while(i==1) {
        int n;
        scanf("%d",&n);
        if(n<=0) {
            i=0;
            break;
        }
        else {
            push(n);
        }
    }
    int element;
    scanf("%d",&element);
    pop(element);
    return 0;
}