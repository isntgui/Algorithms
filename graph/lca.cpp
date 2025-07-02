#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int mxn = 1e5+10, mxl=20;

int up[mxn][mxl], depth[mxn], n, q;
vector<int> adj[mxn];

void dfs(int u, int p) {
	depth[u] = depth[p]+1;
	up[u][0] = p;
	for(int i=1; i<mxl; i++)
		up[u][i] = up[up[u][i-1]][i-1];
	for(int v : adj[u])
		if(v!=p)
			dfs(v, u);
}

int lca(int u, int v) {
	if(depth[u] < depth[v]) swap(u, v);
	int k = depth[u] - depth[v];
	for(int i=mxl-1; i>=0; i--)
		if((k>>i)&1)
			u = up[u][i];
	if(u==v) return u;
	for(int i=mxl-1; i>=0; i--) {
		if(up[u][i]!=up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	}
	return up[u][0];
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	for(int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	depth[0] = -1;
	dfs(1, 0);
	while(q--) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << "\n";
	}
}
