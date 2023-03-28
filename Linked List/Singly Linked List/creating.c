#include<stdio.h>
#include<stdlib.h>

typedef struct myNode { //Node
    int data;
    struct myNode *next;
} Node;

// Declaration of functions that are to be used
Node* create_list(Node*); 
void display(Node*);

//main or the driver function
int main() {
    Node *head = NULL;
    head = create_list(head);
    display(head);
    return 0;
}

//used to display the linked list
void display(Node *head) {
    Node *p;
    for(p=head;p!=NULL;p=p->next) {
        printf("%d ",p->data);
    }
}

//used for creating the linked list in the heap
Node* create_list(Node* head) {
    int i,n;
    Node *p; // pointer that will point to each node of the linked list
    printf("Enter number of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        if(i==0) { //if i==0 means the first location of the linked list and that has to be the head of the linekd list
            head = (Node*)malloc(sizeof(Node));
            p=head;
        }
        else { //in all other cases, Step 1 - creates a new node, Step 2 - the pointer p now point to the newly created node
            p->next = (Node*)malloc(sizeof(Node)); //Step 1
            p=p->next; //Step 2
        }
        printf("Enter Element: \n");
        scanf("%d",&p->data);
    }
    p->next=NULL; //the next part of the last node is assigned with NULL
    return head; //address of the first element, head, of the linked list is returned back
}
