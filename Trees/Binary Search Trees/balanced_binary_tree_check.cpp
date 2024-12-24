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
private: 
    pair<bool, int> checkBalanced(TreeNode* root) {
        if(root==nullptr) {
            return {true, 0};
        }

        pair<bool, int> left=checkBalanced(root->left);
        pair<bool, int> right=checkBalanced(root->right);

        bool leftAns=left.first;
        bool rightAns=right.first;

        bool diff=abs(left.second-right.second)<=1;

        pair<bool, int>ans;
        ans.second=max(left.second, right.second)+1;

        if(leftAns && rightAns && diff)
            ans.first=true;
        else
            ans.second=true;

        return ans;
    }

public:
    bool isBalanced(TreeNode* root) {
        return checkBalanced(root).first;
    }
};
