// time complexity - O(V+E) [direct graph]

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it])
            dfs(it, vis, st, adj);
    }
    st.push(node);
}

vector<int> topoSort(int v, vector<int> adj[]) {
    vector<int> vis(v, 0);
    stack<int> st;
    
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

void displayAdjList(int v, vector<int> adj[]) {
    for (int i = 0; i < v; i++) {
        cout << i << ": ";
        for (auto it : adj[i]) {
            cout << it << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices = 6;
    vector<int> adj[vertices];

    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[5].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(1);

    cout << "Adjacency List:" << endl;
    displayAdjList(vertices, adj);

    vector<int> topoSortResult = topoSort(vertices, adj);

    cout << "Topological Sort: ";
    for (int i : topoSortResult) {
        cout << i << " ";
    }

    return 0;
}
