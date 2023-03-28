#include<stdio.h>
#include<stdlib.h>

typedef struct myNode {
    int data;
    struct myNode *next;
} Node;

Node* create_list(Node*);
Node* insert(Node*, int, int);
void display(Node*);

int main() {
    Node* head=NULL;
    head=create_list(head);
    int pos,val;
    printf("Enter position and value: \n");
    scanf("%d%d",&pos,&val);
    head=insert(head, pos, val);
    display(head);
}

Node* create_list(Node* head) {
int i,n;
Node* p;
printf("Enter number of elements: \n");
scanf("%d",&n);
for(i=0;i<n;i++) {
    if(i==0) {
        head = (Node*)malloc(sizeof(Node));
        p=head;
    }
    else {
        p->next=(Node*)malloc(sizeof(Node));
        p=p->next;
    }
    printf("Enter element: \n");
    scanf("%d",&p->data);
}
p->next=NULL;
return(head);
}

Node* insert(Node* head, int pos, int val) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    Node *p;
    p=head;
    int i=0;
    while(p!=NULL&&i<pos-1) {
        p=p->next;
        i++;
    }
    if(p!=NULL) {
        Node *temp=p->next;
        p->next=newNode;
        newNode->next=temp;
    }
    return(head);
}

void display(Node* head) {
    Node* p;
    for(p=head;p!=NULL;p=p->next)
    printf("%d ",p->data);
}
