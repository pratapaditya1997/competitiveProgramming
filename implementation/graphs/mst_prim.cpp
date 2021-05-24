#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;

int n;                     // number of vertices in the graph
int d[N], p[N], vis[N];    // distance (the edge weight from which you are reaching the node), parent and visited array
vector<pii> g[N], tree[N]; // graph and spanning tree representation

int prim(int source) {
	d.assign(n+1, INT_MAX);
	
	set<pii> s;
	d[source] = 0;
	s.insert({0, source});
	
	int cost = 0;
	while(!s.empty()) {
		int w = s.begin()->first;
		int v = s.begin()->second;
		s.erase(s.begin());
		
		vis[v] = 1;
		cost += w;

		int u = p[v];
		tree[u].push_back({v, w});
		tree[v].push_back({u, w});

		for (int edge: g[v]) {
			int to = edge.first;
			int len = edge.second;
			if (vis[to]) continue;
			if (d[to] > len) {
				// smaller length edge found to vertex 'to'
				s.erase({d[to], to});
				d[to] = len;
				s.insert({d[to], to});
			}
		}
	}
	return cost;
}