#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

pair<bool, int> isSumTree(Node* root) {
    if (root == nullptr) return {true, 0};  
    if (root->left == nullptr && root->right == nullptr)  
        return {true, root->data};

    pair<bool, int> leftAns = isSumTree(root->left);
    pair<bool, int> rightAns = isSumTree(root->right);

    bool condn = root->data == leftAns.second + rightAns.second;

    pair<bool, int> ans;
    if (leftAns.first && rightAns.first && condn) {
        ans.first = true;
        ans.second = 2 * root->data;
    } else {
        ans.first = false;
    }

    return ans;
}

Node* createTree(vector<int> values) {
    if (values.empty()) return nullptr;

    Node* root = new Node(values[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (i < values.size() && !q.empty()) {
        Node* current = q.front();
        q.pop();

        // Left child
        if (i < values.size() && values[i] != -1) {
            current->left = new Node(values[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < values.size() && values[i] != -1) {
            current->right = new Node(values[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Main function
int main() {
    // Example tree creation (1 is the root, -1 indicates no child)
    vector<int> values = {26, 10, 3, 4, 6, -1, -1};  // Example tree: 
                                                      //        26
                                                      //      /    \
                                                      //    10      3
                                                      //   /  \  
                                                      //  4    6

    Node* root = createTree(values);

    // Check if the tree is a Sum Tree
    pair<bool, int> result = isSumTree(root);
    if (result.first)
        cout << "The tree is a Sum Tree." << endl;
    else
        cout << "The tree is not a Sum Tree." << endl;

    return 0;
}
