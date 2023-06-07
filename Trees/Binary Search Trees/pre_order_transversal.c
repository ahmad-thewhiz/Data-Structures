#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createnode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    
    return newNode;
}

struct Node* insertNode(struct Node* root, int value) {
    if(root==NULL) {
        return createnode(value);
    }
    if(value<root->data) {
        root->left=insertNode(root->left, value);
    }
    else if(value>root->data) {
        root->right=insertNode(root->right, value);
    }
    
    return root;
}

void preorder(struct Node* root) {
    if(root==NULL) {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    struct Node *root=NULL;
    int data;
    int i=1;
    while(i==1) {
        scanf("%d",&data);
        if(data<=0) {
            i=0;
            break;
        }
        else {
            root=insertNode(root, data);
        }
    }
    preorder(root);
    return 0;
}
