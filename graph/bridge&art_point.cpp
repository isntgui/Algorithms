#include <bits/stdc++.h>
using namespace std;

// Articulation Point (Pontos críticos que desconectam o grafo)
set<int> ans; 
vector<int> adj[450];
bool vis[450];
int n, m;
int tin[450], low[450]; // Tarjan
int tdfs;

void dfs(int u, int p) {
    vis[u] = true;
    tin[u] = low[u] = tdfs++;
    int children = 0;
    for(int v : adj[u]) {
        if(p==v) continue;
        if(!vis[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v]>=tin[u]&&p!=-1) {
                ans.insert(u);
            }
            children++;
        } else {
            low[u] = min(low[u], tin[v]);
        }
    }
    if(children>1&&p==-1) {
        ans.insert(u);
    }
}

void init() {
    ans.clear();
    for(int i=0; i<=n; i++) {
        adj[i].clear();
        vis[i] = false;
        tin[i] = 0;
        low[i] = 0;
    }
    tdfs = 0;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    init();
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i, -1);
        }
    }
    if(ans.empty())
        cout << "Empty!";
    else 
        for(auto it : ans) cout << it << " ";
    cout << "\n";
}

// Bridge (é uma aresta que, caso seja removida aumenta o número de componentes em um grafo)
