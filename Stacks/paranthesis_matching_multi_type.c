#include<stdio.h>
#include<stdlib.h>

struct node {
    char data;
    struct node *next;
}*top=NULL;

void push(char ch) {
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=ch;
    t->next=top;
    top=t;
}

char pop() {
    struct node *t;
    char x=-1;
    if(top==NULL)
        printf("Stack Empty");
    else {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

int isBalanced(char* exp) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            char ch = pop();
            if (exp[i] == ')' && ch != '(')
                return 0;
            else if (exp[i] == '}' && ch != '{')
                return 0;
            else if (exp[i] == ']' && ch != '[')
                return 0;
        }
    }

    if (top == NULL)
        return 1;
    else
        return 0;
}

int main() {
    char str[1000];
    printf("Enter an expression: ");
    gets(str);
    char *exp=str;
    if(isBalanced(exp)==1)
        printf("\nValid");
    else
        printf("\nInvalid");
    return 0;
}