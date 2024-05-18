// It systematically explores the eedges of G to discover every vertex that is reachable from s.
// For any vertex v reachable from s, the path in the beadth first tree corresponds to the shortest path in graph G from s to v.
// It works on both directed and undirected graphs
// It discovers all vertices at distance k from s before discovering vertices at distance k+1

// space complexity = O(N)
// time complexity = O(2E)
// runs on all degrees


#include <bits/stdc++.h>
using namespace std;

vector<int> bfsGraph(int v, vector<int> adj[]) {
    vector<int> visited(v, 0);  
    visited[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        
        for (auto it : adj[node]) {
            if (!visited[it]) {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    
    return bfs; 
}

int main() {
    int vertices = 9; 
    vector<int> adj[vertices]; 

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(6);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(2);
    adj[4].push_back(2);
    adj[4].push_back(5);
    adj[5].push_back(4);
    adj[5].push_back(7);
    adj[6].push_back(1);
    adj[6].push_back(7);
    adj[6].push_back(8);
    adj[7].push_back(5);
    adj[7].push_back(6);
    adj[8].push_back(6);
    vector<int> bfsResult = bfsGraph(vertices, adj);
    
    cout << "BFS Traversal: ";
    for (int i : bfsResult) {
        cout << i << " ";
    }
    
    return 0;
}
