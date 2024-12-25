class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr=root;

        while(curr!=nullptr) {
            if(curr->left) {
                TreeNode* pred=curr->left;
                while(pred->right)
                        pred=pred->right;
                pred->right=curr->right;
                curr->right=curr->left;
            }
            curr=curr->right;
        }

        curr=root;
        while(curr!=nullptr) {
            curr->left=nullptr;
            curr=curr->right;
        }
    }
};
