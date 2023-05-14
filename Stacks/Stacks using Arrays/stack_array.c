#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *s;
};

void create(struct stack *st) {
    printf("Enter Size\n");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int*)malloc(st->size*sizeof(int));
}

void display(struct stack st) {
    int i;
    for(i=st.top;i>=0;i--)
        printf("%d ",st.s[i]);
    printf("\n");    
}

void push(struct stack *st, int data) {
    if(st->top==st->size-1)
        printf("Overflow\t");
    else {
        st->top++;
        st->s[st->top]=data;
    }
}

int pop(struct stack *st) {
    int x=-1;
    if(st->top==-1)
        printf("Underflow\t");
    else {
        x=st->s[st->top];
        st->top--;
    }
    return x;
}

int peek(struct stack st, int pos) {
    int x=-1;
    if(st.top-pos+1<0)
        printf("Invalid Position\n");
    else {
        x=st.s[st.top-pos+1];
    }
    return x;
}

int stacktop(struct stack st) {
    if(st.top==-1)
        return -1;
    else
        return st.s[st.top];
}

int isEmpty(struct stack st) {
    if(st.top==-1)
        return 1;
    else
        return 0;
} 

int isFull(struct stack st) {
    if(st.top==st.size-1)
        return 1;
    else
        return 0;
}

int main() {
    struct stack st;
    int i,val;
    create(&st);

    for(i=0;i<st.size;i++) {
        printf("Enter element at index %d:\t",(i+1));
        scanf("%d",&val);
        push(&st,val);
    }

    int ch;
    int k=1;
    while(k==1) {
    printf("\nChoose the operation:\n");
    printf("\n1 - Display\n2 - Push\n3 - Pop\n4 - Peek\n5 - Stack Top\n6 - IsEmpty\n7 - IsFull\n8 - Stop\n");
    scanf("%d",&ch);
    int no,data,ans;
    switch(ch) {
        case 1:
        display(st);
        break;
        case 2:
        printf("Enter number of elements:\t");
        scanf("%d",&no);
        st.size+=no;
        for(int j=0;j<no;j++) {
            scanf("%d",&data);
            push(&st,data);
        }
        break;
        case 3:
        printf("Enter number of elements to be popped out\t");
        scanf("%d",&no);
        st.size-=no;
        for(int j=0;j<no;j++) 
            printf("%d\t",pop(&st));
        break;
        case 4:
        printf("Enter position\n");
        scanf("%d",&no);
        ans=peek(st,no);
        printf("%d\n",ans);
        break;
        case 5:
        printf("%d",stacktop(st));
        break;
        case 6:
        ans=isEmpty(st);
        if(ans==1)
            printf("Empty\n");
        else
            printf("Not Empty\n");
        break;
        case 7:
        ans=isFull(st);
        if(ans==1)
            printf("Full\n");
        else
            printf("Not Full\n");
        break;
        case 8:
        k=0;
        break;
        default:
        printf("Wrong Choice\n");
        break;
    }
    }
return 0;
}
