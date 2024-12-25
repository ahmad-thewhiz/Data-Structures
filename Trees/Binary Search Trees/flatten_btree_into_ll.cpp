class Solution {
private:
    void pre_order_traversal(TreeNode* root, vector<int>& res) {
        if (!root) return; 
        res.push_back(root->val);
        pre_order_traversal(root->left, res);
        pre_order_traversal(root->right, res);
    }
public:
    void flatten(TreeNode* root) {
        if (!root) return; // Check for null root
        vector<int> res;
        pre_order_traversal(root, res);
        
        TreeNode* current = root;
        for (int i = 1; i < res.size(); ++i) { // Start from 1 as root is already the first element
            current->left = nullptr;
            current->right = new TreeNode(res[i]);
            current = current->right;
        }
    }
};
