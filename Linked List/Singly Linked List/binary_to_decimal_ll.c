#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* insertion(node* head, int val) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=val;
    newNode->next=NULL;
    
    if(head==NULL) {
        head=newNode;
    }
    else {
        newNode->next=head;
        head=newNode;
    }
    return head;
}

int binary_to_decimal(node* head) {
    int i=0, sum=0;
    node* temp=head;
    while(temp!=NULL) {
        sum=sum+temp->data*pow(2,i);
        i++;
        temp=temp->next;
    }
    return sum;
}

int main() {
    node* head = NULL;
    printf("Enter binary numbers, 0 or 1, any other number to stop\n");
    int flag=1;
    while(flag==1) {
        int val;
        scanf("%d",&val);
        if(val==0 || val==1) {
            head=insertion(head, val);
        }
        else
            flag=0;
    }
    printf("Equivalent Decimal Value %d",binary_to_decimal(head));
    return 0;
}