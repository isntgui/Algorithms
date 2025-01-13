#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1010;

int n, m, d[mxN+1], s;
vector<ar<int, 2>> adj[mxN+1];

int dij(int w, int f) {
	memset(d, 0x3f, sizeof(d));
	d[w]=0;
	priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> pq;
	pq.push({0, s});
	while(pq.size()>0) {
		ar<int, 2> u = pq.top(); pq.pop();
		if(u[0]>d[u[1]])
			continue;
		for(ar<int, 2> vz : adj[u[1]]) {
			if(d[vz[1]]>u[0]+vz[0]) {
				d[vz[1]]=u[0]+vz[0];
				pq.push({d[vz[1]], vz[1]});
			}
		}
	}
	return d[f];
}

void solve() {
	cin >> n >> m;
	for(int i=0, w, x, y; i<m; ++i) {
		cin >> x >> y >> w;
		adj[x].push_back({w, y});
		adj[y].push_back({w, x});
	}
	cin >> s;
	cout << dij(s, 4) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t=1;
	// cin >> t;
	while(t--) solve();
}
