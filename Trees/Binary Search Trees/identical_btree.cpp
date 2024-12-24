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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr)
            return true;
        if((p==nullptr && q!=nullptr) || (q==nullptr && p!=nullptr))
            return false;
        
        bool left = isSameTree(p->right, q->right);
        bool right = isSameTree(p->left, q->left);

        bool check = (p->val == q->val);

        if(left && right && check)
            return true;
        else
            return false;
    }
};
