Problem statement

Write a program to search the element in the circular doubly linked list.

Input format
1.Create

2.Show

3.Search

4.Exit

The first input choice is 1, in which the value can be inserted.

The second input choice is 2, which displays the elements.

The third input choice is 3, in which the value is to be searched.



If the user doesn't enter any of the three choices then display "Please enter valid choice.. "



Output format
Refer to the sample input and output for the formatting specifications.

Sample testcases
Input 1
1
10
1
20
1
30
1
40
2
3
40
4

Output 1
40
30
20
10
item found at location 1

Code:
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node* create_list(struct node *head, int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    newnode->data=val;
    if(head==NULL) {
        head=newnode;
        newnode->next=head;
        newnode->prev=head;
    }
    else {
        temp=head;
        while(temp->next!=head) {
            temp=temp->next;
        }
    
    temp->next=newnode;
    newnode->prev=temp;
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
    }
    return (head);
}

void display(struct node *head) {
    struct node *temp=head;
    do {
        printf("%d\n",temp->data);
        temp=temp->next;
    } while(temp!=head);
}

void search(struct node *head, int ele) {
    struct node *temp=head;
    int i=0,flag=1;
    if(head->data==ele) {
        printf("item found at location %d",i+1);
        flag=0;
    }
    else {
        while(temp->next!=head) {
            if(temp->data==ele) {
                printf("item found at location %d",i+1);
                flag=0;
                break;
            }
            else {
                flag=1;
            }
            i++;
            temp=temp->next;
        }
    }
    if(flag!=0) {
        printf("Item not found\n");
    }
}

int main() {
    int i=1;
    struct node *head=NULL;
    while(i==1) {
        int n;
        scanf("%d",&n);
        switch(n) {
            
            case 1:
            int val;
            scanf("%d",&val);
            head=create_list(head, val);
            break;
            
            case 2:
            display(head);
            break;
            
            case 3:
            int ele;
            scanf("%d",&ele);
            search(head, ele);
            break;
            
            case 4:
            i=0;
            break;
            
            default:
            break;
        }
    }
    return 0;
}