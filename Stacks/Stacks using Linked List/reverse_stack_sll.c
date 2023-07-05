#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

void pop() {
    if (top == NULL) {
        printf("Underflow\n");
    }
    else {
        printf("%d ", top->data);
        struct node *temp = top;
        top = top->next;
        free(temp);
    }
}

void reverseStack() {
    if (top == NULL)
        return;

    struct node *prev = NULL;
    struct node *current = top;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    top = prev;
}

int main() {
    int i = 1;
    while (i == 1) {
        int n;
        scanf("%d", &n);
        if (n <= 0) {
            i = 0;
            break;
        }
        else {
            push(n);
        }
    }
    
    printf("Reversed Stack: ");
    reverseStack();

    return 0;
}
