#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
    char data;
    struct node *next;
}*top=NULL;

void push(char ch) {
    struct node *t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL) 
        printf("Error!");
    else {
        t->data=ch;
        t->next=top;
        top=t;
    }
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

int isOperand(char ch) {
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        return 0;
    else
        return 1;
}

int precedence(char ch) {
    if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='*'||ch=='/')
        return 2;
    else
        return 0;
}

char *convert(char *infix) {
    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));
    while(infix[i]!='\0') {
        if(isOperand(infix[i])) {
            postfix[j++]=infix[i++];
        }
        else {
            if(precedence(infix[i])>precedence(top->data))
                push(infix[i++]);
            else
                postfix[j++]=pop();
        }
    }
    while(top!=NULL) 
        postfix[j++]=pop();
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char str[1000];
    printf("Enter Infix Expression: ");
    gets(str);
    char *infix=str;
    push('#');
    char *postfix=convert(infix);
    printf("%s ",postfix);
    return 0;
}

