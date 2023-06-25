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

int max_depth(bnode* root) {
    if(root==NULL)
        return 0;
    int ldepth = max_depth(root->left);
    int rdepth = max_depth(root->right);

    return (ldepth>rdepth) ? ldepth+1 : rdepth+1;
}

void inorder_display(bnode* root) {
    if(root==NULL)
        return;
    inorder_display(root->left);
    printf("%d ", root->data);
    inorder_display(root->right);
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
    printf("\nInorder Display:\n");
    inorder_display(root);
    printf("\nHeight: %d",max_depth(root));
    return 0;
}



