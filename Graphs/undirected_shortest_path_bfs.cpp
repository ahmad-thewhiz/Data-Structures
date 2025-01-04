
#include<bits/stdc++.h>

using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int, vector<int>>adj;

	for(int i=0;i<edges.size();i++) {
		int u=edges[i].first;
		int v=edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}


	vector<bool>visited(n,false);
	unordered_map<int, int>parent;
	queue<int>q;

	q.push(s);
	visited[s]=true;
	parent[s]=-1;

	// bfs traversal
	while(!q.empty()) {
		int front=q.front();
		q.pop();

		for(auto it:adj[front]) {
			if(!visited[it]) {
				visited[it]=true;
				parent[it]=front;
				q.push(it);
			}
		}
	}

	// prepare shortest path
	vector<int>ans;
	int curr=t;
	ans.push_back(t);

	while(curr!=s) {
		curr=parent[curr];
		ans.push_back(curr);
	}

	reverse(ans.begin(), ans.end());

	return ans;
	
}
