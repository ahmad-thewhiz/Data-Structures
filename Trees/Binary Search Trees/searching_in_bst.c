#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} bnode;

bnode *newNode(int data) {
    bnode* temp = (bnode*)malloc(sizeof(bnode));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

bnode *insert_node(bnode *root, int data) {
    if(root==NULL)
        return newNode(data);
    if(data<root->data)
        root->left=insert_node(root->left, data);
    else if(data>root->data)
        root->right=insert_node(root->right, data);
    return root;
} 

int search_bnode(bnode* root, int ele) {
    while(root!=NULL) {
        if(ele==root->data)
            return 1;
        else if(ele>root->data)
            root=root->right;
        else if(ele<root->data)
            root=root->left;
    }
    return 0;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    bnode* root=NULL;
    int val;
    printf("\nEnter values :");
    for(int i=0;i<n;i++) {
        scanf("%d",&val);
        root=insert_node(root, val);
    }
    printf("\nEnter element to be searched: ");
    int ele;
    scanf("%d",&ele);
    if(search_bnode(root, ele))
        printf("\nFound");
    else
        printf("\nNot Found");
    return 0;
}




