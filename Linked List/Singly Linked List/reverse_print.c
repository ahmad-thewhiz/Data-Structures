#include<stdio.h>
#include<stdlib.h>

typedef struct myNode {
    int data;
    struct myNode *next;
} Node;

Node* create_list(Node*);
void revdisplay(Node*);

int main() {
    Node* head = NULL;
    head=create_list(head);
    revdisplay(head);
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

void revdisplay(Node* head) {
    if(head==NULL)
    return ;
    revdisplay(head->next);
    printf("%d ",head->data);
}
