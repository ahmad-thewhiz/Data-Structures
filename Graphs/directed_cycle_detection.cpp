#include<bits/stdc++.h>

bool checkCycle(int node, unordered_map<int, bool>&vis, unordered_map<int, bool>&dfsVis, unordered_map<int, list<int>>adj) {
  vis[node]=true;
  dfsVis[node]=true;

  for(auto it:adj[node]) {
    if(!vis[it]) {
      bool cycleDetected=checkCycle(it, vis, dfsVis, adj);
      if(cycleDetected)
        return true;
    }
    else if(dfsVis[it])
        return true;
  }

  dfsVis[node]=false;
  return false;
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int, list<int>>adj;

  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;

    adj[u].push_back(v);
  }

  unordered_map<int, bool>vis;
  unordered_map<int, bool>dfsVis;

  for(int i=1;i<=n;i++) {
    if(!vis[i]){
      bool cycleFound=checkCycle(i, vis, dfsVis, adj);
      if(cycleFound)
        return true;
    }
  }
  return false;
}
