// Time Complexity = O(V*E)

#include<bits/stdc++.h>

using namespace std;

vector<int> bellman_ford(int v, vector<vector<int>> &edges, int s) {
    vector<int>dist(v, 1e8);
    dist[s]=0
    for(int i=0;i<v-1;i++) {
        for(auto it: edges) {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=1e8 && dist[u]+wt<dist[v]) {
                dist[v]=dist[u]+wt;
            }
        }
    }
    //N-th relaxation to checknegative cycle
    for(auto it: edges) {
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if(dist[u]!=1e8 && dist[u]+wt<dist[v]) {
            return {-1};
        }
    }
    return dist;
}
