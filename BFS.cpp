#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1011];
int n, m;

string bfs(int w, int f) {
	vector<bool> v(n+1, 0);
	v[w]=1;
	queue<int> q;
	q.push(w);
	while(q.size()>0) {
		int u=q.front(); q.pop();
		for(auto &x : adj[u]) {
			if(!v[x]) {
				v[x] = 1;
				q.push(x);
			}
		}
	}
	return (v[f]?"Encontrado":"Nao econtrado");
}

void solve() {
	cin >> n >> m;
	for(int i=0, x, y; i<m; ++i) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout << bfs(1, 5) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t=1;
	// cin >> t;
	while(t--) solve();
}