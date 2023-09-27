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

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    
    for (int i = 0; postfix[i]; ++i) {
        if (isdigit(postfix[i])) {
            push(stack, postfix[i] - '0'); // Convert char to int
        } else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            switch (postfix[i]) {
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
                    printf("Invalid operator: %c\n", postfix[i]);
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
    char postfix[] = "452*+3+"; // Example postfix expression
    int result = evaluatePostfix(postfix);
    if (result != -1) {
        printf("Result: %d\n", result);
    }
    return 0;
}
