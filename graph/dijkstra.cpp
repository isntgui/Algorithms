#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5 + 10;
const long long INF = 4e18;

int n, m;
vector<pair<int, int>> adj[mxn];
long long dist[mxn];

void dijkstra(int s) {
	fill(dist, dist + n + 1, INF);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	dist[s] = 0;
	pq.push({0, s});
	while(!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if(d >= dist[u])
			continue;
		for(auto [v, w] : adj[u]) {
			if(dist[v] > d + w) {
				dist[v] = d + w;
				pq.push({dist[v], v});
			}
		}
	}
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ;
}