#include<bits/stdc++.h>
using namespace std;

const int mxN=1e4+10;
int n, m;
bool v[mxN+1];
vector<int> adj[mxN];

void dfs(int w) {
	v[w] = true;
	for(auto &x : adj[w])
		if(!v[x])
			dfs(x);
}

void solve() {
	cin >> n >> m;
	memset(v, 0, sizeof(v));
	for(int i=0, x, y; i<m; ++i) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1);
	if(v[5])
		cout << "Encontrado\n";
	else
		cout << "Nao encontrado\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t=1;
	// cin >> t;
	while(t--) solve();
}