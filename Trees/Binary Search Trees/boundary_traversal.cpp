class Solution {
private:
    // Traverse the left boundary excluding leaf nodes
    void traverseLeft(Node* root, vector<int> &ans) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;
        
        ans.push_back(root->data);
        
        if (root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
    }

    // Traverse all the leaf nodes
    void traverseLeaf(Node* root, vector<int> &ans) {
        if (root == NULL)
            return;
        
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    
    // Traverse the right boundary excluding leaf nodes
    void traverseRight(Node* root, vector<int> &ans) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;
        
        if (root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);
        
        ans.push_back(root->data); // Add after child to ensure reverse order
    }

public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        
        // Add the root data
        ans.push_back(root->data);
        
        // Traverse the left boundary excluding the root and leaf nodes
        traverseLeft(root->left, ans);
        
        // Traverse all the leaf nodes
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
        
        // Traverse the right boundary excluding the root and leaf nodes
        traverseRight(root->right, ans);
        
        return ans;
    }
};
