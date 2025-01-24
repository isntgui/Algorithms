#include<bits/stdc++.h>
using namespace std;

const int mxN = 5e4+1e2;

int grauEn[mxN];
vector<int> adj[mxN];

vector<int> ord_tp(int v) {
    vector<int> lista;
    queue<int> q;
    for (int i = 1; i <= v; ++i)
        if (grauEn[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int V = q.front(); q.pop();
        lista.push_back(V);
        for (int w : adj[V]) {
            --grauEn[w];
            if (grauEn[w] == 0)
                q.push(w);
        }
    }
    if ((int)lista.size() != v)
        throw runtime_error("O grafo possui ciclos");
    
    return lista;
}

void solve() {
    int v;
    cin >> v;
    for (int i = 0, x, y; i < v; ++i) {
        cin >> x >> y;
        ++grauEn[y];
        adj[x].push_back(y);
    }
    try {
        vector<int> ans = ord_tp(v);
        cout << "Ordenação topologica: ";
        for (int v : ans) 
            cout << v << " ";
        cout << "\n";
    } catch (const runtime_error &e) {
        cout << e.what() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
    
    return 0;
}
