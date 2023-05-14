#include<stdio.h>

char a[1000];
int top=-1;
int n;

void push(char ch) {
    if(top==n) {
        printf("Overflow");
        return;
    }
    else {
        a[++top]=ch;
    }
}

void pop() {
    if(top==-1) {
        printf("Underflow");
        return;
    }
    else {
        printf("%c ",a[top--]);
    }
}

int main() {
    scanf("%d",&n);
    char str[100];
    scanf("%s",str);
    for(int i=0;i<n;i++) {
        push(str[i]);
    }
    for(int i=0;i<n;i++) 
    pop();
    return 0;
}