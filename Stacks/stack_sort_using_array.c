#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *S;
};

void create(struct stack *s) {
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);
    s->size = size;
    s->top = -1;
    s->S = (int*)malloc(size * sizeof(int));
}

void push(struct stack *s, int val) {
    if (s->top == s->size - 1)
        printf("Stack Overflow");
    else {
        s->top++;
        s->S[s->top] = val;
    }
}

int pop(struct stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow");
        return -1; // or handle the underflow case appropriately
    }
    else {
        int x = s->S[s->top];
        s->top--;
        return x;
    }
}

void sort(struct stack *s) {
    struct stack t;
    create(&t); // Create temporary stack t
    while (s->top != -1) {
        int a = pop(s); // Pop element from original stack
        while (t.top != -1 && a < t.S[t.top]) {
            // If the current element is smaller than the top element of t,
            // move the top element of t back to the original stack
            push(s, pop(&t));
        }
        // Push the current element to t
        push(&t, a);
    }
    // Copy elements from t back to the original stack
    while (t.top != -1) {
        push(s, pop(&t));
    }
}

void Display(struct stack s) {
    for(int i=s.top;i>=0;i--)
        printf("%d ",s.S[i]);
    printf("\n");
}

int main() {
    struct stack s;
    create(&s); 
    printf("Enter values in the stack: ");
    for(int i=0;i<s.size;i++) {
        int val;
        scanf("%d",&val);
        push(&s,val);
    }
    printf("\nBefore Sorting:\n");
    Display(s);
    sort(&s);
    printf("\nAfter Sorting\n");
    Display(s);
    return 0;
    }
