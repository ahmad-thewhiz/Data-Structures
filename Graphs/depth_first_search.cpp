// space complexity = O(N)
// time complexity =  O(N) + (2E) [undirected graph]

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls) {
    vis[node] = 1;
    ls.push_back(node);
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis, ls);
        }
    }
}

vector<int> dfsGraph(int v, vector<int> adj[]) {
    vector<int> vis(v, 0);
    vector<int> ls; // list to store particular dfs
    dfs(0, adj, vis, ls); // Start DFS from node 0
    return ls;
}

int main() {
    int vertices = 8; 
    vector<int> adj[vertices]; 

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(4);
    adj[1].push_back(5);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[2].push_back(7);
    adj[3].push_back(2);
    adj[3].push_back(7);
    adj[4].push_back(1);
    adj[5].push_back(1);
    adj[6].push_back(2);
    adj[6].push_back(7);
    adj[7].push_back(3);
    adj[7].push_back(6);

    vector<int> dfsResult = dfsGraph(vertices, adj);
    
    cout << "DFS Traversal: ";
    for (int i : dfsResult) {
        cout << i << " ";
    }
    
    return 0;
}
