#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> cap; // stores capacity for every pair of vertices
vector<vector<int>> g;   // undirected graph, since we are also keeping the reversed edges


/**
* constructs augmenting path and returns flow
*/
int bfs(int s, int t, vector<int>& par) {
	fill(par.begin(), par.end(), -1);
	par[s] = -2;
	queue<pair<int, int>> q;
	q.push({s, inf});

	while(!q.empty()) {
		int v = q.front().first;
		int flow = q.front().second;
		q.pop();

		for (int to: g[v]) {
			if (par[to] == -1 && cap[v][to]) {
				par[to] = v;
				int new_flow = min(flow, cap[v][to]);
				if (to == t) return new_flow;
				q.push({to, new_flow});
			}
		}
	}
	return 0;
}

/**
* O(VE^2)
*/
int maxflow(int s, int t) {
	int flow = 0;
	vector<int> par(n);
	int new_flow;

	while (new_flow = bfs(s, t, par)) {
		flow += new_flow;
		int cur = t;
		while (cur != s) {
			int prev = par[cur];
			cap[prev][cur] -= new_flow;
			cap[cur][prev] += new_flow;
			cur = prev;
		}
	}

	return flow;
}

int main() {
	return 0;
}