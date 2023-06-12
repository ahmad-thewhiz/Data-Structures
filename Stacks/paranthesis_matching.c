#include<stdio.h>

struct node {
    char data;
    struct node *next;
}*top=NULL;

void push(char ch) {
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    
    if(t==NULL)
        printf("Stack Full");
    else {
        t->data=ch;
        t->next=top;
        top=t;
    }
}

char pop() {
    struct node *t;
    char x=-1;
    if(top==NULL) {
        printf("Stack Empty");
    }
    else {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

//This function checks if the number of opening brackets are equal to the number of closing brackets or not
int isBalanced(char *exp) {
    int i;
    for(i=0;exp[i]!='\0';i++) {
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')') {
            if(top==NULL)
                return 0;
            pop();
        }         
    }
    if(top==NULL) //is stack has become empty at the last then return 1 (true)
        return 1;
    else
        return 0;
}

int main() {
    char str[1000];
    printf("Enter an expression: ");
    gets(str);
    char *exp = str;
    if(isBalanced(exp)==1)
        printf("Valid");
    else
        printf("Invalid");
    return 0;    
}

