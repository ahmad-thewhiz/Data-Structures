#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
    bool leftT;
    bool rightT;
} Node;

Node* createNode(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value=value;
    temp->right=temp->left=NULL;
    temp->rightT=temp->leftT=true;
    return temp;
}

Node* insertion(Node* root, int value) {
    if(root==NULL)
        return createNode(value);
        
    Node* curr = root;
    Node* parent = NULL;

    while(curr!=NULL) {
        
        if(root->value==value)
            return root;  
            
        parent = curr;
        
        if(value<curr->value) {
            if(curr->leftT == false) //leftT=true means that it is a thread
                curr = curr->left;
            else
                break; //right position to insert reached
        }
        else {
            if(curr->rightT == false) 
                curr = curr->right;
            else
                break; //right position to insert reached
        }
    }
    
    Node* newNode = createNode(value);
    if(value<parent->value) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->leftT = false; // there is no thread rather a child is present
        parent->left = newNode;
    }
    else {
        newNode->right = parent->right;
        newNode->left = parent;
        parent->rightT = false;
        parent->right = newNode; 
    }
    return root;
}

void inOrder(Node* root) {
    if (root == NULL)
        return;
        
    Node* curr = root;
    
    while (curr->leftT == false)
        curr = curr->left;
        
    while (curr != NULL) {
        printf("%d ", curr->value);
        
        if (curr->rightT == true)
            curr = curr->right;
        else {
            curr = curr->right;
            while (curr != NULL && curr->leftT == false)
                curr = curr->left;
        }
    }
}

Node* searchKey(Node* root, int key) {
    Node* curr = root;
    
    while(curr!=NULL) {
        if(curr->value==key)
            return curr;
    
        else if(key < curr->value)
            curr = curr->left;
        
        else
            curr = curr->right;
    }
    return NULL;
}

Node* findInOrderPredecessor(Node* node) {
    if (node == NULL) return NULL;
    Node* curr = node->left;
    while (curr != NULL && curr->rightT == false) {
        curr = curr->right;
    }
    return curr;
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL) return root;

    // Find the node to delete
    Node* curr = root;
    Node* parent = NULL;
    while (curr != NULL && curr->value != value) {
        parent = curr;
        if (value < curr->value) {
            if (curr->leftT == false) {
                curr = curr->left;
            } else {
                return root; // Node not found
            }
        } else {
            if (curr->rightT == false) {
                curr = curr->right;
            } else {
                return root; // Node not found
            }
        }
    }

    if (curr == NULL) return root; // Node not found

    // Case 1: Node has no children
    if (curr->leftT && curr->rightT) {
        if (parent == NULL) {
            // Deleting the root node
            free(curr);
            return NULL;
        }
        if (curr == parent->left) {
            parent->leftT = true;
            parent->left = curr->left;
        } else {
            parent->rightT = true;
            parent->right = curr->right;
        }
        free(curr);
    }
    
    // Case 2: Node has one child
    else if (curr->leftT || curr->rightT) {
        Node* child = (curr->leftT) ? curr->left : curr->right;
        if (parent == NULL) {
            root = child;
        } else if (curr == parent->left) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        free(curr);
    }
    // Case 3: Node has two children
    else {
        Node* predecessor = findInOrderPredecessor(curr);
        int predVal = predecessor->value;
        root = deleteNode(root, predecessor->value); // Delete predecessor
        curr->value = predVal; // Replace current node's value with predecessor's
    }

    return root;
}



int main() {
    Node* root = NULL;
    
    root = insertion(root, 20);
    root = insertion(root, 10);
    root = insertion(root, 30);
    root = insertion(root, 5);
    root = insertion(root, 15);

    printf("Inorder traversal of Threaded BTree: ");
    inOrder(root);
    
    printf("\nEnter Key to be searched: ");
    int key;
    scanf("%d", &key);
    Node* keyNode = searchKey(root, key);
    if (keyNode)
        printf("%d found\n", keyNode->value);
    else
        printf("Key not found\n");
    
    printf("\nEnter Key to be deleted: ");
    int key_del;
    scanf("%d", &key_del);

    // Check if the key exists before attempting to delete
    Node* keyToDelete = searchKey(root, key_del);
    if (keyToDelete) {
        root = deleteNode(root, key_del);
        printf("Updated Inorder traversal of Threaded BTree: ");
        inOrder(root);
    } else {
        printf("Key not found. Nothing to delete.\n");
    }

    return 0;
}
