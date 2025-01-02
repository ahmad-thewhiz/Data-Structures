void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ls) {
    vis[node] = 1;
    ls.push_back(node);
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis, ls);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    // Convert edge list to adjacency list
    vector<vector<int>> adj(V);
    for (const auto &edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<int> vis(V, 0);
    vector<vector<int>> res;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            vector<int> ls;
            dfs(i, adj, vis, ls);
            res.push_back(ls);
        }
    }

    return res;
}
