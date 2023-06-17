/*
General algorithm to delete a node from a BST:
l. start
2. if a node to be deleted is a leaf nod at left side then simply delete and set null pointer to
it's parent's left pointer.
3. If a node to be deleted is a leaf node at right side then simply delete and set null pointer
to it's parent's right pointer
if a node to be deleted has orfchild then connect it's child pointer with it's parent pointer
4. and delete it from the Kee
5. if a node to be deleted has two children then replace the node being deleted either by
a. right most node of it's left sub-tree or
b. left most node of it's right sub-tree.
6. End
*/

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

bnode* minValNode(bnode* node) {
    if(node==NULL)
        return;
    else if(node->left==NULL)
        return node;
    else
        return (minValNode(node->left));
}

bnode* deleteNode(bnode* root, int ele) {
    if(root==NULL)
        return root;
    
    if(ele<root->data)
        root->left = deleteNode(root->left, ele);
    else if(ele>root->data)
        root->right = deleteNode(root->right, ele);
    else if(root->left!=NULL && root->right!=NULL) {
        bnode* temp;
        temp=minValNode(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right, root->data);
    }
    else {
        bnode* temp=root;
        if(root->left==NULL) 
            root=root->right;
        else if(root->right==NULL)
            root=root->left;
        free(temp);
    }
    return root;
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
    printf("\nEnter element to be deleted: ");
    int ele;
    scanf("%d",&ele);
    root=deleteNode(root, ele);
    printf("\nUpdated Tree: ");
    inorder_display(root);
    return 0;

}

