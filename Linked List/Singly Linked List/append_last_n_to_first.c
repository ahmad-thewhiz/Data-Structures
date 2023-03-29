#include<stdio.h>
#include<stdlib.h>

typedef struct myNode {
    int data;
    struct myNode *next;
} Node;

Node* create_list(Node*);
Node* append_last_n_to_first(Node*, int );
void display(Node*);

int main() {
    Node* head=NULL;
    head=create_list(head);
    int loc;
    printf("Enter location:\n");
    scanf("%d",&loc);
    head=append_last_n_to_first(head, loc);
    display(head);
    return 1;
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

Node* append_last_n_to_first(Node* head, int loc) {
    if(head==NULL||loc==0)
    return head;
    else {
Node *temp,*initial,*fast,*slow;
initial=head;
fast=head;
slow=head;
int i=0;
while(fast->next!=NULL)
fast=fast->next;
while(slow!=NULL&&i<loc-1) {
    slow=slow->next;
    i++;
}
temp=slow->next;
slow->next=NULL;
fast->next=initial;
head=temp;
return(head);
    }
}

void display(Node* head) {
    Node* p;
    for(p=head;p!=NULL;p=p->next)
    printf("%d ",p->data);
}