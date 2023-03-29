#include<stdio.h>
#include<stdlib.h>

typedef struct myNode {
    int data;
    struct myNode *next;
} Node;

Node* create_list(Node*);
int length(Node*);

int main() {
    Node* head = NULL;
    head=create_list(head);
    int len=length(head);
    printf("Length is: %d",len);
    return 1;
}

Node* create_list(Node* head) {
int n;
Node* p;
printf("Enter -1 to stop\n");
printf("Enter element: \n");
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
    p->data=n;
    printf("Enter element: \n");
    scanf("%d",&n);
}
p->next=NULL;
return(head);
}

int length(Node* head) {
    if(head==NULL)
    return 0;
    return 1+length(head->next);
    }
