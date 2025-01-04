#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<pair<int, int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++) {
        int u = edges[i].first - 1; 
        int v = edges[i].second - 1; 
        adj[u].push_back(v);
    }

    vector<int> inDegree(v, 0);
    for (auto it : adj) {
        for (auto j : it.second)
            inDegree[j]++;
    }

    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto it : adj[front]) {
            inDegree[it]--;
            if (inDegree[it] == 0)
                q.push(it);
        }
    }

    if (ans.size() != v) {
        // If not all nodes are processed, there is a cycle in the graph
        return {};
    }

    return ans;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    vector<int> topo = topologicalSort(edges, n, edges.size());

    if (topo.empty())
        return 1; 

    return 0;
}
