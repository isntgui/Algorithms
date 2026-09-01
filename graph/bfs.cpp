#include <bits/stdc++.h>
using namespace std;

bool vis[110];
vector<vector<int>> adj;

void bfs(int st) {
	queue<int> q;
	q.push(st);
	vis[st] = true;
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		for (auto v : adj[u]) {
			if (!vis[v]) {
				q.push(v);
				vis[v] = true;
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	;
}