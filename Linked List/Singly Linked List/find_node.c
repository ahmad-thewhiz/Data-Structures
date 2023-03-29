#include<stdio.h>
#include<stdlib.h>

typedef struct myNode {
    int data;
    struct myNode *next;
} Node;

Node* create_list(Node*);
int find_node(Node*, int);
void display(head);

int main() {
    Node* head=NULL;
    head=create_list(head);
    int val;
    printf("Enter the number to be located: \n");
    scanf("%d",&val);
    int pos = find_node(head, val);
    display(head);
    printf("\n%d",pos);
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

int find_node(Node* head, int val) {
    Node* p=head;
    int i=0,pos=-1;
    while(p!=NULL) {
        if(p->data==val) {
            pos=i;
            break;
    }
    else {
        p=p->next;
        i++;
    }
    }
    return pos;
    }

void display(Node* head) {
    Node* p;
    for(p=head;p!=NULL;p=p->next)
    printf("%d ",p->data);
}