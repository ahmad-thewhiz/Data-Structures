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

bnode* findNode(bnode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    
    bnode* rightChild = findNode(root->right, data);
    if (rightChild != NULL) {
        return rightChild;
    }
    
    return findNode(root->right, data);
}

int getRightChild(bnode* root, int data) {
    bnode* node = findNode(root, data);
    if (node == NULL || node->right == NULL) {
        return -1; // Left child does not exist
    }
    return node->right->data;
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
    int parent;
    printf("\nEnter node: ");
    scanf("%d",&parent);
    printf("\n%d",getRightChild(root, parent));
    return 0;
}
