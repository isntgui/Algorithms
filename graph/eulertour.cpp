#include <bits/stdc++.h>
using namespace std;

constexpr int mxn = 1e4+10;

int n, m;
vector<int> adj[mxn];
int timer;
int time_in[mxn], time_out[mxn];

void dfs(int u, int p) {
    time_in[u] = ++timer;
    for(auto v : adj[u]) if (v!=p) {
        dfs(v, u);
    }
    time_out[u] = timer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    timer = 0;
    for(int i=1; i<=n; i++) if(time_in[i]==0) {
        dfs(i, i);
    }
}
