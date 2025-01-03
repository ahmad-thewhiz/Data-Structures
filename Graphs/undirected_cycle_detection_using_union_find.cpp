class Solution {
private:
    int findParent(int node, vector<int>& parent) {
        if (parent[node] != node)
            parent[node] = findParent(parent[node], parent);
        return parent[node];
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
        
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            int parentU = findParent(u, parent);
            int parentV = findParent(v, parent);
            
            if (parentU == parentV)
                return edge;
            
            // Union the sets by setting the parent of one root to the other
            parent[parentV] = parentU;
        }
        
        return {};
    }
};
