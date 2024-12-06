#include <bits/stdc++.h>

using namespace std;

#define V 9  // Number of vertices in the graph


// Function to find the vertex with the minimum distance value
int minDistance(const vector<int>& dist, const vector<bool>& sptSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}


void dijkstra(const vector<vector<int>>& graph, int src) {
    vector<int> dist(V, INT_MAX);  // Distance array to store the shortest path
    vector<bool> sptSet(V, false); // sptSet[i] will be true if vertex i is included in the shortest path tree

    dist[src] = 0;  // Distance from source to itself is 0

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);  // Pick the vertex with the minimum distance

        sptSet[u] = true;  // Mark the picked vertex as processed

        // Update the distance values of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex Distance from Source " << src << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 0, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 0},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 0, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 0, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);  
    return 0;
}
