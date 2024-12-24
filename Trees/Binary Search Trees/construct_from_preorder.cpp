class Solution {
private:
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap) {
        
        // base case where start indices exceed the end indices                  
        if(preStart>preEnd || inStart>inEnd)
            return nullptr;
                            
        // a new node with value at the current preorder index
        TreeNode* root = new TreeNode(preorder[preStart]);

        // index of current root value in the order traversal
        int inRoot = inMap[root->val];

        // number of elements in the left subtree
        int numsLeft = inRoot-inStart;

        // recursively build the left subtree
        root->left = buildTree(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, inMap);
        
        // recursively build the right subtree
        root->right = buildTree(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, inMap);

        // return the current root node
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;

        for(int i=0;i<inorder.size();i++)
            inMap[inorder[i]] = i;

        TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
    }
};
