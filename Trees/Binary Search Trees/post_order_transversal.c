#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};


struct Node* createNode(int value) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct Node* insertNode(struct Node* node, int value) {
    if(node==NULL)
        return createNode(value);
    if(value<node->data)
        node->left=insertNode(node->left, value);
    else if(value>node->data)
        node->right = insertNode(node->right, value);
    return node;
}

void postorder(struct Node* node) {
    if(node==NULL)
    return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ",node->data);
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
            root = insertNode(root, data);
        }
    }
    postorder(root);
    return 0;
}
