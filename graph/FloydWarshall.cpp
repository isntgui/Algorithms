#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=100, inf=0x3f3f3f3f;

int n, m, adj[mxN+1][mxN+1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    memset(adj, 0x3f, sizeof(adj));
    for(int i=0, u, v, w; i<m; ++i) {
        cin >> u >> v >> w;
        if(adj[u][v]>100||adj[u][v]>w)
            adj[u][v] = adj[v][u] = w;
    }
    for(int i=0; i<n; ++i) adj[i][i] = 0;
    for(int k=0; k<n; ++k)
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
    int ans = inf;
    for(int i=0; i<n; ++i) {
        int cur_d = -1;
        for(int j=0; j<n; ++j)
            cur_d = max(cur_d, adj[j][i]);
        ans = min(ans, cur_d);
    }
    cout << ans << "\n";
}
