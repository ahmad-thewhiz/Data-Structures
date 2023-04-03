#include<stdio.h>
#include<stdlib.h>

typedef struct myNode {
    int data;
    struct myNode *next;
} Node;

Node* create_list(Node*);
void display(Node*);

int main() {
    Node* head=NULL;
    head=create_list(head);
    display(head);
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
p->next=head; //last element will point to the first element
return(head);
}

void display(Node* head) {
    Node* p=head;
    do {
    printf("%d ",p->data);
    p=p->next;
    } while(p!=head); //since this is a d-while loop, it will skip the first case when p==head and continue to print until head comes again
    printf("\n");
}


