/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        vector<vector<int>> res;
        queue<TreeNode*> q; 

        q.push(root); 
        q.push(nullptr); 

        vector<int> temp;

        while (!q.empty()) { 
            TreeNode* n = q.front(); 
            q.pop(); 

            if (n != nullptr) {
                temp.push_back(n->val); 
                if (n->left != nullptr)
                    q.push(n->left); 
                if (n->right != nullptr)
                    q.push(n->right); 
            } else {
                res.push_back(temp); 
                temp.clear(); 
                if (!q.empty()) 
                    q.push(nullptr);
            }
        }
        return res;
    }
};
