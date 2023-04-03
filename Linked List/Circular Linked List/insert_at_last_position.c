#include<stdio.h>
#include<stdlib.h>

typedef struct myNode {
    int data;
    struct myNode *next;
} Node;

Node* create_cll(Node*);
Node* insert_last(Node*, int);
void display(Node*);

int main() {
    Node* head=NULL;
    head=create_cll(head);
    int x;
    printf("Enter element to be inserted: \n");
    scanf("%d",&x);
    head=insert_last(head, x);
    display(head);
    return 1;
}

Node* create_cll(Node* head) 
{
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

Node* insert_last(Node* head, int ele) {
        Node *p=head;
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data=ele;

        do { //loop to make pointer p reach at last node before head
            p=p->next;
        } while (p->next!=head);
        
        p->next=newNode; //last node will pont to new node
        newNode->next=head; //new node will point to head
        /* in this case new node will be made head because we have to insert an element at the last*/
        return(head);
}
 
void display(Node* head) {
    Node* p=head;
    do {
        printf("%d ",p->data);
        p=p->next;
    } while(p!=head);
}