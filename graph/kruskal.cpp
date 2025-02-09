#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef pair<int, pair<int, int>> edge;

class UionFind {
private:
	vector<int> parent, rank;
public:
	UionFind(int n) {
		parent.assign(n+1, 0);
		rank.assign(n+1, 0);
		for(int i=0; i<=n; ++i) parent[i]=i;
	}
	int find(int i) {
		return (parent[i]==i) ? i : (parent[i]=find(parent[i]));
	}
	bool comp(int i, int j) {
		return find(i)==find(j);
	}
	void unioSet(int i, int j) {
		if(!comp(i, j)) {
			int x = find(i), y=find(j);
			if(rank[x]>rank[y])
				parent[y] = x;
			else {
				parent[x] = y;
				if(rank[x]==rank[y])
					++rank[y];
			}
		}
	}
};

int kruskal(int n, const vector<edge> &adj) {
	UionFind UF(n);
	int ans = 0;
	for(auto e : adj) {
		int u=e.S.F, w=e.S.S;
		if(!UF.comp(u, w)) {
			UF.unioSet(u, w);
			ans+=e.F;
		}
	}
	return ans;
}

void solve() {
	int v, a;
	while(cin >> v >> a && v) {
		vector<edge> adj;
		int tc=0;
		for(int i=0, u, w, p; i<a; ++i) {
			cin >> u >> w >> p;
			adj.push_back({p, {u, w}});
			tc+=p;
		}
		sort(adj.begin(), adj.end());
		int eit = kruskal(v, adj);
		cout << tc-eit << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	int t=1;
	// cin >> t;
	while(t--) 
		solve();
}
