#include <stdio.h>
#include <stdlib.h>

struct Node
    {
        int data;
        struct Node *next;
    }*front=NULL,*rear=NULL;

void enqueue(int x)
    {
        struct Node *t;
        t=(struct Node*)malloc(sizeof(struct Node));
        if(t==NULL)
        printf("Queue is FUll\n");
        else
        {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
        front=rear=t;
        else
        {
        rear->next=t;
        rear=t;
        }
    }

}

int dequeue()
    {
    int x=-1;
    struct Node* t;

    if(front==NULL)
    printf("Queue is Empty\n");
    else
    {
    x=front->data;
    t=front;
    front=front->next;
    free(t);
    }
    return x;
}

void Display()
    {
    struct Node *p=front;
    while(p)
    {
    printf("%d ",p->data);
    p=p->next;
    }
    printf("\n");
}

int main()
    {
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
    return 0;
}