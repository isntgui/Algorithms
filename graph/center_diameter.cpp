#include<bits/stdc++.h>
using namespace std;

const int mxn=1e5+10, INF=1e9+10;

// Diametro de uma arvore (dois pares de vertices que possuem a maior distancia da arvore)
int n, dist[mxn];
bool vis[mxn];
vector<int> adj[mxn];

void bfs(int w) {
    memset(vis, 0, sizeof vis);
    memset(dist, 0, sizeof dist);
    vis[w]=1;
    queue<int> q;
    q.push(w);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int vz : adj[u]) {
            if(!vis[vz]) {
                dist[vz] = dist[u]+1;
                vis[vz] = 1;
                q.push(vz);
            }
        }
    }
}

// Centro de uma arvore (o vertice que minimiza a distancia para todos os outros vertices)
int pai[mxn];
int dist1[2][mxn];

void dfs(int w, int p, int d, int q) {
    dist1[q][w] = d;
    pai[w] = p;
    for(int vz : adj[w]) {
        if(vz!=p)
            dfs(vz, w, d+1, q);
    }
}

int center(int u, int v) {
    dfs(u, -1, 0, 0);
    dfs(v, -1, 0, 1);
    int at=u, mn=INF, c=u;
    while(at!=-1) {
        if(max(dist1[0][at], dist1[1][at])<mn)
            mn = max(dist1[0][at], dist1[1][at]), c=at;
        at = pai[at];
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=1; i<n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    int mp1=-1, u=-1;
    for(int i=1; i<=n; ++i)
        if(mp1<dist[i])
            mp1 = dist[i], u=i;
    bfs(u);
    int diametro=-1, v=-1;
    for(int i=1; i<=n; ++i)
        if(diametro<dist[i])
            diametro = dist[i], v=i;
    cout << u << " -> " << v << " = " << diametro << "\n";
    cout << "O centro da arvore eh: ";
    cout << center(u, v) << "\n";
}
