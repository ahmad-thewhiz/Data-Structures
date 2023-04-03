#include<stdio.h>
#include<stdlib.h>

typedef struct myNode {
    int data;
    struct myNode *next;
} Node;

Node* create_cll(Node*);
Node* insert_ele(Node*, Node*, int, int);
int length(Node*);
void display(Node*);

int main() {
    Node* head=NULL;
    head=create_cll(head);
    int pos,x;
    printf("Enter index and element: \n");
    scanf("%d%d",&pos,&x);
    head=insert_ele(head, head, pos, x);
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

Node* insert_ele(Node* head, Node* p, int pos, int x) {
    Node* t;
    int i;
    if(pos<0||pos>length(p))
    return ;
    if(pos==0) { //if insertion has to be done at the first position
        t=(Node*)malloc(sizeof(Node));
        t->data=x;
        if(head==NULL) {
            head=t;
            head->next=head;
        }
        else {
            while(p->next!=head) //to add a new element to the first position, we have to tranverse till the end
            p=p->next;
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else { //if insertion has to be done at nth position
        for(i=0;i<pos-1;i++)
        p=p->next;
        t=(Node*)malloc(sizeof(Node));
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
    return(head);
}

int length(Node* head) {
    int len=0;
    Node* p=head;
    do {
        len++;
        p=p->next;
    } while(p!=head);
    return len;
}

void display(Node* head) {
    Node* p=head;
    do {
        printf("%d ",p->data);
        p=p->next;
    } while(p!=head);
}
