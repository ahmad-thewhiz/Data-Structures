#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int front;
    int rear;
    int *Q;
} queue;

// Function to create a queue
void create(queue *q, int size) {
    q->size = size;
    q->Q = (int *)malloc(size * sizeof(int));
    q->front = q->rear = -1;
}

// Function to check if the queue is full
int isFull(queue *q) {
    return q->rear == q->size - 1;
}

// Function to check if the queue is empty
int isEmpty(queue *q) {
    return q->front == q->rear;
}

// Function to enqueue an element into the queue
void enqueue(queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
    } else {
        q->rear++;
        q->Q[q->rear] = value;
    }
}

// Function to dequeue an element from the queue
int dequeue(queue *q) {
    int x = -1;
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
    } else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

// Function to display the contents of the queue
void display(queue q) {
    if (isEmpty(&q)) {
        printf("Queue Empty\n");
    } else {
        for (int i = q.front + 1; i <= q.rear; i++) {
            printf("%d ", q.Q[i]);
        }
        printf("\n");
    }
}

int main() {
    queue q;
    int n;

    // Get the size of the queue from the user
    printf("Enter size of the queue: ");
    scanf("%d", &n);

    // Create the queue
    create(&q, n);

    // Get values to enqueue into the queue
    printf("\nEnter the values in the queue: ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(&q, val);
    }

    // Display the initial queue
    printf("Current Queue:\n");
    display(q);

    int com;
    printf("\nEnter number of elements to be dequeued: ");
    scanf("%d", &com);
    // Dequeue an element from the queue
    for(int i=0;i<com;i++) {
        int ele = dequeue(&q);
        printf("\nDeleted Element: %d\n", ele);
    }
    
    // Display the updated queue
    printf("Updated Queue:\n");
    display(q);

    return 0;
}
