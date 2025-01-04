#include<bits/stdc++.h>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<int> &vis, unordered_map<int, int> &parent) {
    vis[src] = 1;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto it : adj[front]) {
            if (vis[it] && it != parent[front]) {
                return true; // Cycle detected
            } else if (!vis[it]) {
                q.push(it);
                vis[it] = 1;
                parent[it] = front;
            }
        }
    }

    return false;
}


string cycleDetection(vector<vector<int>> &edges, int n, int m) {
    // Adjusted adjacency list size for 1-based indexing
    vector<vector<int>> adj(n + 1);
    for (auto edge : edges) {
        // Assuming edge[0] and edge[1] are 1-based
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]); // For undirected graph
    }

    unordered_map<int, int> parent;
    // Adjusted vis vector size for 1-based indexing
    vector<int> vis(n + 1, 0);

    // Loop from 1 to n for 1-based nodes
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            parent[i] = -1; // Initialize parent of starting node
            if (isCycle(i, adj, vis, parent)) {
                return "Yes";
            }
        }
    }
    return "No";
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges(m, vector<int>(2));
        for(int i = 0; i < m; ++i){
            cin >> edges[i][0] >> edges[i][1];
        }
        cout << cycleDetection(edges, n, m) << "\n";
    }
}
