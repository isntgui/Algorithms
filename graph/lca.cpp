#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int mxn = 1e5+10, mxl = 30;

vector<int> adj[mxn];
int depth[mxn], pai[mxn], up[mxn][mxl], n, m;

void bld() {
	fill(pai, pai+n+1, -1);
	fill(depth, depth+n+1, -1);
	memset(up, -1, sizeof up);
}

void dfs(int w=1, int p=-1, int d=0) {
	pai[w] = p;
	depth[w] = d;
	up[w][0] = p;
	for(int i=1; i<mxl; ++i) 
		if(up[w][i-1]!=-1)
			up[w][i] = up[up[w][i-1]][i-1];
	for(int vz : adj[w]) {
		if(vz!=p)
			dfs(vz, w, d+1);
	}
}

int lca(int u, int v) {
	if(depth[u] < depth[v]) swap(u, v);
	for(int i=mxl-1; i>=0; --i)
		if(depth[u]-(1<<i) >= depth[v])
			u = up[u][i];
	if(u==v) return u;
	for(int i=mxl-1; i>=0; --i)
		if(up[u][i]!=up[v][i]) {
			u = up[u][i];
			v = up[v][i];	
		}
	return pai[u];
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	bld();
	for(int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	int q;
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << "\n";
	}
}
