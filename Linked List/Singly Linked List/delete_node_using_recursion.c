#include<stdio.h>
#include<stdlib.h>

typedef struct myNode {
    int data;
    struct myNode *next;
} Node;

Node* create_list(Node*);
Node* delete_node(Node*, int);
void display(head);

int main() {
    Node* head=NULL;
    head=create_list(head);
    int pos;
    printf("Enter the position of the element to be deleted: \n");
    scanf("%d",&pos);
    head=delete_node(head, pos);
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

Node* delete_node(Node* head, int pos) {
    if(head==NULL)
    return head;
    else if(pos==0) {
        Node* temp=head;
        head=head->next;
        free(temp);
        return(head);
    }
    else {
        head->next=delete_node(head->next,pos-1);
        return head;
    }
}

void display(Node* head) {
    Node* p;
    for(p=head;p!=NULL;p=p->next)
    printf("%d ",p->data);
}