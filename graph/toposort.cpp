#include <bits/stdc++.h>
using namespace std;

vector<int> kahnTopoSort(int n, const vector<vector<int>>& adj) {
    vector<int> in_degree(n, 0);

    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            in_degree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0)
            q.push(i);
    }

    vector<int> topo_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    if ((int)topo_order.size() != n) {
        return {};
    }

    return topo_order;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> result = kahnTopoSort(n, adj);

    if (result.empty()) {
        cout << "O grafo possui ciclo. Ordenação topológica nao e possivel.\n";
    } else {
        cout << "Ordenacao topologica:\n";
        for (int u : result) {
            cout << u << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
