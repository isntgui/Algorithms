#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int vertices, arestas;
    cin >> vertices >> arestas;
    vector<vector<pair<int, int>>> adj; // (peso, destino)
    adj.resize(vertices+1);
    for(int i=0; i<arestas; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].emplace_back(w, y);
        adj[y].emplace_back(w, x);
    }
    int inicio;
    cin >> inicio;
    // Dijkstra
    vector<int> dist(vertices+1, (int)1e9+10);
    dist[inicio] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, inicio);
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if(d>dist[u])
            continue;
        for(auto [ps, vz] : adj[u]) {
            if(ps+d < dist[vz]) {
                dist[vz] = ps+d;
                pq.emplace(dist[vz], vz);
            }
        }
    }
    for(int i=1; i<=vertices; ++i)
        cout << dist[i] << " ";
    cout << "\n";
}
