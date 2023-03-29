#include<stdio.h>
#include<stdlib.h>

typedef struct myNode {
    int data;
    struct myNode *next;
} Node;

Node* create_list(Node*);
int count(Node*);

int main() {
    Node* head=NULL;
    head=create_list(head);
    int length=count(head);
    printf("Length of the Linked List is: %d",length);
    return 1;
}

Node* create_list(Node* head) {
int n;
Node* p;
printf("Enter elements; Type -1 to stop \n");
scanf("%d",&n);
while(n!=-1) {
    if(head==NULL) {
        head = (Node*)malloc(sizeof(Node));
        p=head;
    }
    else {
        p->next=(Node*)malloc(sizeof(Node));
        p=p->next;
    }
    printf("Enter element: \n");
    p->data=n;
    scanf("%d",&n);
}
p->next=NULL;
return(head);
}

int count(Node* head) {
    Node* p;
    int count=0;
    for(p=head;p!=NULL;p=p->next) {
        count++;
    }
    return count;
}
