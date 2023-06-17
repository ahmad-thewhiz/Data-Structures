#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} bnode;

bnode* newNode(int data) {
    bnode* temp = (bnode*)malloc(sizeof(bnode));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

bnode *insertion(bnode* root, int data) {
    if(root == NULL) 
        return newNode(data);

    if(data>root->data) 
        root->right=insertion(root->right, data);
    else if(data<root->data)
        root->left=insertion(root->left, data);
    return root;
}

int FindMax(bnode* root) {
    bnode* curr=root;
    while(curr->right!=NULL)
        curr=curr->right;
    return(curr->data);
}

void inorder_display(bnode* root) {
    if(root==NULL)
        return;
    inorder_display(root->left);
    printf("%d ",root->data);
    inorder_display(root->right);
}

int main() {
    bnode* root=NULL;
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("\nEnter Values: ");
    int val;
    for(int i=0;i<n;i++) {
        scanf("%d",&val);
        root=insertion(root, val);
    }
    printf("\nInorder Transversal: ");
    inorder_display(root);
    printf("\nMax Element: %d",FindMax(root));
    return 0;
}