// Kahn's Algorithm is a method for topological sorting of a directed acyclic graph (DAG). 
// It uses an **indegree array** to keep track of the number of incoming edges for each vertex. 
// Initially, all vertices with an indegree of 0 are added to a queue. 
// Vertices are then dequeued one by one, and their neighbors' indegree is reduced. 
// If a neighbor's indegree becomes 0, it is added to the queue. 
// This process continues until the queue is empty. 
// If all vertices are processed, a valid topological order is produced; otherwise, the graph contains a cycle.

#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;
    
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Initialize indegree array
    vector<int> inDegree(v, 0);
    for (auto it : adj) {
        for (auto j : it.second)
            inDegree[j]++;
    }

    // Push all vertices with indegree 0 into the queue
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

        // Reduce indegree for neighbors and push them to queue if indegree becomes 0
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
