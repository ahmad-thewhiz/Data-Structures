#include <stdio.h> 
#include <stdlib.h> 

struct Node 
{ 
  int data; 
  struct Node *next; 
  struct Node *prev;     
}; 

void reverse(struct Node **head_ref);
void push(struct Node** head_ref, int new_data);
void printList(struct Node *node); 

void reverse(struct Node **head) {
    struct Node* temp=NULL;
    struct Node* curr=*head;
    
    while(curr!=NULL) {
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    if(temp!=NULL) {
        *head=temp->prev;
    }
}

void push(struct Node **head, int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->prev=NULL;
    newNode->next=*head;
    if(*head!=NULL) {
        (*head)->prev=newNode;
    }
    *head=newNode;
}

void printList(struct Node *head) {
    while(head!=NULL) {
        printf("%d ",head->data);
        head=head->next;
    }
}

int main() 
{ 
  struct Node* head = NULL; 
  int val;
  for(int i = 0;i<5;i++)
  {
      scanf("%d", &val);
      push(&head, val); 
  }
    printList(head);
  reverse(&head);
  printf("\n");
  printList(head);            
  return 0;
} 