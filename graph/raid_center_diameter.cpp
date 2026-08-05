/*
Diâmetro = maior distância entre dois vértices em uma árvore.
Raio = menor distância máxima de um vértice para os outros.
Centro = vértice que minimiza a maior distância para todos os outros vértices.
*/

#include <bits/stdc++.h>
using namespace std;

#if __has_include("debugging.h")
#include "debugging.h"
#endif

#define int long long int

#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()

constexpr int mxn = 1e3 + 5, INF = 2e18;

vector<pair<int, int>> adj[mxn], edge;
int dist[mxn], pai[mxn];

int bfs(int s) {
    fill(dist, dist + mxn, -1);
    fill(pai, pai + mxn, -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    pai[s] = 0;
    int far = s;  // vertice mais distante
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (dist[u] > dist[far]) {
            far = u;
        }
        for (auto [v, w] : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + w;
                pai[v] = u;
                q.push(v);
            }
        }
    }
    return far;
}

tuple<int, int, int> diam_raio_centro(int u) {
    int A = bfs(u);  // encontrar o vertice mais distante
    int B = bfs(A);  // encontrar o vertice mais distante de A

    int diametro = dist[B];

    vector<int> path;  // caminho do diâmetro
    int curr = B;
    while (curr != 0) {
        path.push_back(curr);
        curr = pai[curr];
    }

    int raio = INF;
    int centro = -1;

    for (int node : path) {
        int d = max(dist[node], diametro - dist[node]);

        if (d < raio) {
            raio = d;
            centro = node;
        }
    }

    if (path.empty()) {
        raio = 0;
        centro = u;
    }

    return {diametro, raio, centro};
}

/* Versão para grafos
Obs: Ao tratar com grafos ponderados use Dijkstra.
tuple<int,int,int> diam_raio_centro(int n){
    vector<int> ecc(n + 1);
    int diametro = 0;
    int raio = INF;
    int centro = -1;
    for(int s = 1; s <= n; s++){
        fill(dist, dist + n + 1, -1);
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                if(dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        int mx = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == -1){
                mx = INF;
                break;
            }
            mx = max(mx, dist[i]);
        }
        ecc[s] = mx;
        diametro = max(diametro, mx);
        if(mx < raio){
            raio = mx;
            centro = s;
        }
    }
    return {diametro, raio, centro};
}
*/

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    auto [diametro, raio, centro] = diam_raio_centro(1);
    cout << "Diametro = " << diametro << '\n';
    cout << "Raio = " << raio << '\n';
    cout << "Centro = " << centro << '\n';
}
