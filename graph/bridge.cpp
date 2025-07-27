#include <bits/stdc++.h>
using namespace std;

constexpr int mxn = 450;

// bridge é dois pares (u, v) se caso forem removidos aumentariam o número de componentes conexas

int n, m, tdfs;
vector<int> adj[mxn];
bool vis[mxn];
int tin[mxn], low[mxn];
set<pair<int, int>> bridges;

void dfs(int u, int p) {
    vis[u] = true;
    tin[u] = low[u] = tdfs++;
    for(auto v : adj[u]) {
        if(v==p) continue;
        if(vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v]>tin[u]) {
                bridges.emplace(make_pair(u, v));
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    tdfs = 0;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i, -1);
        }
    }
    for(auto [u, v] : bridges) {
        cout << u << " " << v << "\n";
    }
    cout << "\n";
}
