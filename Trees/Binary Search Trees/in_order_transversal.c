#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createnode(int value) {
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct Node *insertnode(struct Node* root, int value) {
    if(root==NULL) {
    return createnode(value);
    }
    if(value < root->data) 
    root->left=insertnode(root->left,value);
    else if(value > root->data)
    root->right=insertnode(root->right,value);
    
    return root;
}

void inorder(struct Node* root) {
    if(root==NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main() {
    struct Node* root=NULL;
    
    int data;
    int i=1;
    while(i==1) {
        scanf("%d",&data);
        if(data<=0) {
            i=0;
            break;
        }
        else {
            root=insertnode(root, data);
        }
    }
    inorder(root);
    return 0;
}
