#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int mxn = 1e5+10, mxl = 20;

int n, q, up[mxn][mxl], depth[mxn];
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

int bl(int u, int k) {
	if(depth[u]<k) return -1;
	for(int i=mxl-1; i>=0; i--)
		if((k>>i)&1)
			u = up[u][i];
	return u;
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
		int u, k;
		cin >> u >> k;
		cout << bl(u, k) << "\n";
	}
}
