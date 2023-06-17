#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *right;
}bnode;

bnode* create_node(int data) {
    bnode* temp = (bnode*)malloc(sizeof(bnode));
    temp->data=data;
    temp->right=NULL;
    return temp;
}

bnode* insertion(bnode* root, int val) {
    if(root==NULL)
        return create_node(val);
    root->right=insertion(root->right, val);
    return root;
}

void inorder_display(bnode* root) {
    if(root==NULL)
        return;
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
}
