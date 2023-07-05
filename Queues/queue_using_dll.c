#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
} *front, *rear;

struct node* create_node(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=newNode->prev=NULL;
    return newNode;
}

void enqueue(int data) {
    struct node* temp=create_node(data);
    if(front==NULL&&rear==NULL)
        front=rear=temp;
    else {
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
    }
}

int dequeue() {
    int x = front->data;
    struct node* temp=NULL;
    temp=front;
    front=front->next;
    front->prev=NULL;
    free(temp);
    return x;
}

void Display() {
    struct node *p=front;
    while(p)
    {
    printf("%d ",p->data);
    p=p->next;
    }
    printf("\n");
}

int main() {
int size;
        printf("Enter number of elements to be enqueued: ");
        scanf("%d", &size);
        int val;
        for(int i=0;i<size;i++) {
            scanf("%d",&val);
            enqueue(val);
        }
        
        printf("\nCurrent Queue: ");
        Display();
        
        printf("\nEnter number of elements to be dequeued: ");
        int no;
        scanf("%d", &no);
        for (int i = 0; i < no; i++) {
        int ele = dequeue();
        printf("\nDeleted Element: %d", ele);

        printf("\nUpdated Queue: ");
        Display();
}
}
