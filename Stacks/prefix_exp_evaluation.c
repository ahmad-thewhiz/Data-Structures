#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define a structure for the stack
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Function to create a stack of a given capacity
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

// Function to evaluate a prefix expression
int evaluatePrefix(char* prefix) {
    struct Stack* stack = createStack(strlen(prefix));
    
    // Reverse the prefix expression to process it from right to left
    for (int i = strlen(prefix) - 1; i >= 0; --i) {
        if (isdigit(prefix[i])) {
            push(stack, prefix[i] - '0'); // Convert char to int
        } else {
            int operand1 = pop(stack);
            int operand2 = pop(stack);
            switch (prefix[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", prefix[i]);
                    return -1; // Error
            }
        }
    }
    
    int result = pop(stack);
    free(stack->array);
    free(stack);
    return result;
}

int main() {
    char prefix[] = "+*45+23"; // Example prefix expression
    int result = evaluatePrefix(prefix);
    if (result != -1) {
        printf("Result: %d\n", result);
    }
    return 0;
}
