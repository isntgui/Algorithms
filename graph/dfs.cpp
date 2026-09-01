#include <bits/stdc++.h>
using namespace std;

vector<int> adj[110];
bool vis[110];

void dfs(int u) {
	vis[u] = true;
	for (auto v : adj[u]) {
		if (!vis[v]) {
			dfs(v);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	
}