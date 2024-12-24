class Solution {
private:
    TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd,
                        vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap) {
        // Base case: if indices are invalid, return nullptr
        if (postStart > postEnd || inStart > inEnd)
            return nullptr;
        
        // Create root node with the current postorder element
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        // Find the root index in the inorder traversal
        int inRoot = inMap[root->val];
        
        // Calculate the number of nodes in the left subtree
        int numsLeft = inRoot - inStart;
        
        // Recursively build the right subtree first
        root->right = buildTree(postorder, postStart + numsLeft, postEnd - 1,
                                inorder, inRoot + 1, inEnd, inMap);
        
        // Recursively build the left subtree
        root->left = buildTree(postorder, postStart, postStart + numsLeft - 1,
                               inorder, inStart, inRoot - 1, inMap);
        
        // Return the current root node
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Create a hash map for quick lookup of indices in inorder
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;
        
        TreeNode* root = buildTree(postorder, 0, postorder.size() - 1,
                                   inorder, 0, inorder.size() - 1, inMap);
        return root;
    }
};
