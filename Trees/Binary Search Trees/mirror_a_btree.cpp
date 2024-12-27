class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node==NULL)
            return;
        
        mirror(node->left);
        mirror(node->right);
        
        swap(node->left, node->right);
    }
};
