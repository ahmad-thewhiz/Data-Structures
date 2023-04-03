#include<stdio.h>
#include<stdlib.h>

typedef struct myNode {
    int data;
    struct myNode *next;
} Node;

Node* create_cll(Node*);
Node* delete_first(Node*);
void display(Node*);

int main() {
    Node* head=NULL;
    head=create_cll(head);
    head=delete_first(head);
    display(head);
    return 1;
}

Node* create_cll(Node* head) {
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
p->next=head;
return(head);
}

Node* delete_first(Node* head) {
    Node* p=head; //pointer pointing to the head of the circular linked list
    do { //loop transvering till the end of cirular linked list
        p=p->next;
    } while(p->next!=head);

    p->next=head->next; //last element will point to the element next to head
    head=head->next; //head will begin from the element next to head
    return(head);
}

void display(Node* head) {
    Node* p=head;
    do {
        printf("%d ",p->data);
        p=p->next;
    } while(p!=head);
}