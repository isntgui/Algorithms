#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=5e4+500, mxL=20;

int n, x, depth[mxN+1], pai[mxN+1], c[mxN],
	par[mxN], ancestral[mxN][mxL];

vector<int> adj[mxN];

void dfs(int w) {
	for(int i=0; i<(int)adj[w].size(); ++i) {
		int v = adj[w][i];
		if(depth[v]==-1) {
			pai[v] = w;
			depth[v] = depth[w]+1;
			dfs(v);
		}
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	for(int i=mxL-1; i>=0; --i)
		if(depth[a] - (1<<i) >= depth[b])
			a = ancestral[a][i];
	if(a==b) return a;
	for(int i=mxL-1; i>=0; --i) 
		if(ancestral[a][i]!=-1&&ancestral[a][i] != ancestral[b][i])
			a = ancestral[a][i], b=ancestral[b][i];
	return pai[a];
}

void solve() {
	cin >> n;
	for(int i=1, x; i<=n; ++i) {
		cin >> x;
		if(c[x]) {
			par[i] = c[x];
			par[c[x]] = i;
		}
		c[x] = i;
	}
	for(int i=1, w, x; i<n; ++i) {
		cin >> w >> x;
		adj[w].push_back(x);
		adj[x].push_back(w);
	}
	memset(depth, -1, sizeof(depth));
	memset(pai, -1, sizeof(pai));
	memset(ancestral, -1, sizeof(ancestral));
	depth[1] = 0;
	dfs(1);
	for(int i=1; i<=n; ++i) ancestral[i][0] = pai[i];
	for(int j=1; j<mxL; ++j)
		for(int i=1; i<=n; ++i)
			ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
	ll ans=0;
	for(int i=1; i<=n; ++i)
		ans+=(ll)(depth[i]+depth[par[i]]-2*depth[lca(i, par[i])]);
	cout << ans/2 << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t=1;
	// cin >> t;
	while(t--) solve();
}