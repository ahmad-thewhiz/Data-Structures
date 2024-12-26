class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int>res;
        
        if(root==NULL)
            return res;
            
        map<int, int>mapp;
        
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto it=q.front();
            q.pop();
            
            Node* node=it.first;
            int line=it.second;
            
            mapp[line]=node->data;
            
            if(node->left)
                q.push({node->left, line-1});
            if(node->right)
                q.push({node->right, line+1});
        }
        
        for(auto it:mapp)
            res.push_back(it.second);
        
        return res;
    }
};
