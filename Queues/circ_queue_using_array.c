#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int front;
    int rear;
    int *Q;
} circ_queue;

// Function to create a circular queue
void create(circ_queue *cq, int size) {
    cq->size = size;
    cq->Q = (int *)malloc(size * sizeof(int));
    cq->front = cq->rear = -1;
}

// Function to enqueue an element into the circular queue
void enqueue(circ_queue *cq, int value) {
    if (((cq->rear + 1) % cq->size) == cq->front) {
        printf("Queue Overflow\n");
    } else {
        cq->rear = (cq->rear + 1) % cq->size;
        cq->Q[cq->rear] = value;
    }
}

// Function to dequeue an element from the circular queue
int dequeue(circ_queue *cq) {
    int x = -1;
    if (cq->front == cq->rear) {
        printf("Queue Underflow\n");
    } else {
        cq->front = (cq->front + 1) % cq->size;
        x = cq->Q[cq->front];
    }
    return x;
}

// Function to display the contents of the circular queue
void display(circ_queue cq) {
    int i = (cq.front + 1) % cq.size;
    do {
        printf("%d ", cq.Q[i]);
        i = (i + 1) % cq.size;
    } while (i != (cq.rear + 1) % cq.size);
    printf("\n");
}

int main() {
    circ_queue cq;
    int size;

    // Get the number of elements to be enqueued from the user
    printf("Enter number of elements to be enqueued: ");
    scanf("%d", &size);

    // Create the circular queue
    create(&cq, size);

    // Get elements to enqueue into the circular queue
    printf("\nEnter the elements: ");
    for (int i = 0; i < size; i++) {
        int no;
        scanf("%d", &no);
        enqueue(&cq, no);
    }

    // Display the current circular queue
    printf("\nCurrent Queue: ");
    display(cq);

    // Get the number of elements to be dequeued from the user
    printf("\nEnter number of elements to be dequeued: ");
    int no;
    scanf("%d", &no);
    for (int i = 0; i < no; i++) {
        int ele = dequeue(&cq);
        printf("\nDeleted Element: %d", ele);
    }

    // Display the updated circular queue
    printf("\nUpdated Queue: ");
    display(cq);

    return 0;
}
