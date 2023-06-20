#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *right;
    struct node *left;
}bnode;

bnode* create_node(int data) {
    bnode* newNode = (bnode*)malloc(sizeof(bnode));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

bnode* insert_node(bnode* root, int data) {
    if(root==NULL)
        return create_node(data);
    if(data>root->data)
        root->right = insert_node(root->right, data);
    else if(data<root->data)
        root->left = insert_node(root->left, data);
    return root; 
}

int find_parent(bnode* root, int node_val, int parent) {
    if(root==NULL)
        return -1;
    if(root->data==node_val)
        return parent;
    else {
        find_parent(root->left, node_val, root->data);
        find_parent(root->right, node_val, root->data);
    }
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
    int child;
    printf("\nEnter node: ");
    scanf("%d",&child);
    printf("\n%d",find_parent(root, child, -1));
    return 0;
}
