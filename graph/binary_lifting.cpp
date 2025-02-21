#include <bits/stdc++.h>
using namespace std;

const int mxl=30, mxn=1e5+10;

int parent[mxn][mxl], depth[mxn], n, m, q, k, v;
vector<int> adj[mxn];

void bld() {
    memset(parent, -1, sizeof(parent));
    memset(depth, -1, sizeof(depth));
}

void dfs(int node=0, int par=-1, int d=0) {
    depth[node] = d;
    parent[node][0] = par;
    for(int i=1; i<=mxl; ++i)
        if(parent[node][i-1] != -1)
            parent[node][i] = parent[parent[node][i-1]][i-1];
    for(auto ch : adj[node])
        if(ch!=par)
            dfs(ch, node, d+1);
}

int bl(int node, int k) {
    if(depth[node]<k)
        return -1;
    for(int i=mxl; i>=0; --i)
        if(k>=(1 << i))
            node = parent[node][i], k -= (1 << i);
    return node;
}

int main() {
    cin >> n >> m;
    bld();
    for(int i=0, x, y; i<m; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs();
    cin >> q;
    while(q--) {
        cin >> v >> k;
        cout << bl(v, k) << "\n";
    }
}
