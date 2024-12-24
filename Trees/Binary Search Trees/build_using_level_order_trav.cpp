#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    struct node *left;
    struct node *right;

   node(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

void printLevelOrder(node* root) {
    if(root==nullptr)
        return ;
        
    queue<node*> q;
    q.push(root);
    q.push(nullptr);
    
    vector<int>temp;
    
    while(!q.empty()) {
        bool leftToRight=true;
        
        node *n = q.front();
        q.pop();
        
        if(n!=nullptr) {
            temp.push_back(n->val);
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        } else {
            for(int num:temp)
                cout<<num<<" ";
            cout<<endl;
            temp.clear();
            if(!q.empty())
                q.push(nullptr);
        }
        }
    } 

void buildFromLevelOrder(node*& root) {  
    
    queue<node*> q;

    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;

    root = new node(data);  
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->val << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1) {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->val << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1) {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main() {
    node* root = nullptr;  

    buildFromLevelOrder(root);
    
    printLevelOrder(root);

    return 0;
}

// #### **2. Building the Binary Tree from Level Order Input**

// **Function:** `buildFromLevelOrder(node*& root)`

// **Steps:**
// 1. **Initialize:**
//    - Create an empty queue to keep track of nodes (`queue<node*> q`).

// 2. **Input Root Node:**
//    - Prompt the user: "Enter data for root:"
//    - Read integer input `data`.
//    - If `data` is not `-1`:
//      - Create the root node with `data`.
//      - Assign it to `root`.
//      - Enqueue the root node into the queue.

// 3. **Iteratively Build the Tree:**
//    - **While** the queue is not empty:
//      1. **Dequeue Current Node:**
//         - Remove the front node from the queue and assign it to `temp`.
     
//      2. **Input Left Child:**
//         - Prompt the user: "Enter left node for: `temp->val`"
//         - Read integer input `leftData`.
//         - If `leftData` is not `-1`:
//           - Create a new node with `leftData`.
//           - Assign it as the `left` child of `temp`.
//           - Enqueue the left child node into the queue.
     
//      3. **Input Right Child:**
//         - Prompt the user: "Enter right node for: `temp->val`"
//         - Read integer input `rightData`.
//         - If `rightData` is not `-1`:
//           - Create a new node with `rightData`.
//           - Assign it as the `right` child of `temp`.
//           - Enqueue the right child node into the queue.

// #### **3. Printing the Binary Tree in Level Order**

// **Function:** `printLevelOrder(node* root)`

// **Steps:**
// 1. **Check for Empty Tree:**
//    - If `root` is `nullptr`, terminate the function.

// 2. **Initialize for Traversal:**
//    - Create an empty queue (`queue<node*> q`).
//    - Enqueue the `root` node.
//    - Enqueue a `nullptr` marker to indicate the end of the first level.
//    - Create an empty list/vector `temp` to store node values of the current level.

// 3. **Iteratively Traverse the Tree:**
//    - **While** the queue is not empty:
//      1. **Dequeue a Node:**
//         - Remove the front node from the queue and assign it to `n`.
     
//      2. **Process the Node:**
//         - **If** `n` is not `nullptr`:
//           - Add `n->val` to the `temp` list.
//           - **If** `n->left` exists, enqueue `n->left`.
//           - **If** `n->right` exists, enqueue `n->right`.
        
//         - **Else** (`nullptr` marker encountered):
//           - **Print Current Level:**
//             - Iterate through `temp` and print each value separated by a space.
//             - Print a newline to separate levels.
//           - **Prepare for Next Level:**
//             - Clear the `temp` list.
//             - **If** the queue is not empty, enqueue another `nullptr` marker to indicate the end of the next level.


