#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a structure for the stack
struct Stack {
    int top;
    int capacity;
    char* array;
};

// Function to create a stack of a given capacity
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push a character onto the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

// Function to get the precedence of an operator
int getPrecedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix to prefix expression
void infixToPrefix(char* infix, char* prefix) {
    int len = strlen(infix);
    
    // Reverse the input infix expression
    char reversed[len + 1];
    for (int i = 0, j = len - 1; i < len; i++, j--) {
        if (infix[i] == '(')
            reversed[j] = ')';
        else if (infix[i] == ')')
            reversed[j] = '(';
        else
            reversed[j] = infix[i];
    }
    reversed[len] = '\0';
    
    // Initialize the stack for conversion
    struct Stack* stack = createStack(len);
    int j = 0;  // Index for the prefix expression
    
    for (int i = 0; reversed[i]; i++) {
        if (isalnum(reversed[i])) {
            prefix[j++] = reversed[i]; // Operand, copy to prefix
        } else if (reversed[i] == ')') {
            push(stack, reversed[i]); // Push closing parenthesis onto the stack
        } else if (reversed[i] == '(') {
            // Pop from the stack until a matching ')' is found
            while (!isEmpty(stack) && stack->array[stack->top] != ')') {
                prefix[j++] = pop(stack);
            }
            pop(stack); // Pop the matching ')'
        } else {
            // Operator encountered
            while (!isEmpty(stack) && getPrecedence(reversed[i]) <= getPrecedence(stack->array[stack->top])) {
                prefix[j++] = pop(stack);
            }
            push(stack, reversed[i]); // Push the operator onto the stack
        }
    }
    
    // Pop any remaining operators from the stack
    while (!isEmpty(stack)) {
        prefix[j++] = pop(stack);
    }
    
    prefix[j] = '\0';
    
    // Reverse the prefix expression to get the final result
    len = strlen(prefix);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = prefix[i];
        prefix[i] = prefix[j];
        prefix[j] = temp;
    }
}

int main() {
    char infix[] = "4+5*2+3"; // Example infix expression
    char prefix[strlen(infix) + 1];
    
    infixToPrefix(infix, prefix);
    
    printf("Infix: %s\n", infix);
    printf("Prefix: %s\n", prefix);
    
    return 0;
}
