#include <bits/stdc++.h>
using namespace std;

// Código Tarjan

int id = 0, n, m;
vector<vector<int>> adj;
vector<int> ids, low;
vector<bool> onStack;
stack<int> s;
vector<vector<int>> sccs;

void dfs(int w) {
    s.push(w);
    onStack[w] = 1;
    ids[w] = low[w] = id++;

    for (int to : adj[w]) {
        if (ids[to] == -1) {
            dfs(to);
            low[w] = min(low[w], low[to]);
        } else if (onStack[to]) {
            low[w] = min(low[w], ids[to]);
        }
    }

    if (ids[w] == low[w]) {
        vector<int> scc;
        while (true) {
            int node = s.top();
            s.pop();
            onStack[node] = false;
            scc.push_back(node);
            low[node] = ids[w];
            if (node == w) break;
        }
        sccs.push_back(scc);
    }
}

void setsccs() {
    adj.resize(n);
    ids.resize(n, -1);
    low.resize(n);
    onStack.resize(n, false);
}

int main() {
    cin >> n >> m;
    setsccs();
    for(int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i=0; i<n; ++i) {
        if (ids[i] == -1) {
            dfs(i);
        }
    }
    cout << "Componentes Fortemente Conectadas:\n";
    for (const auto& scc : sccs) {
        for (int node : scc) {
            cout << node << " ";
        }
        cout << "\n";
    }
}

// Código Kosajaru

#include<bits/stdc++.h>
using namespace std;

const int mxn = 1e4+10;

int n, components[mxn], visitados[mxn];
vector<int> grafo[mxn], reverso[mxn], saida;

void dfs1(int w) {
    visitados[w]=1;
    for(auto vz : grafo[w])
        if(visitados[vz]==0)
            dfs1(vz);
    saida.emplace_back(w);
}

void dfs2(int w, int c) {
    visitados[w] = 2;
    components[w] = c;
    for(int vz : reverso[w])
        if(visitados[vz]==1)
            dfs2(vz, c);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        grafo[a].emplace_back(b);
        reverso[b].emplace_back(a);
    }
    for(int i=1; i<=n; ++i)
        if(visitados[i]==0)
            dfs1(i);
    int componente = 0;
    for(int i=(int)saida.size()-1; i>=0; --i) {
        if(visitados[saida[i]]==1) {
            ++componente;
            dfs2(saida[i], componente);
        }
    }
    for(int i=1; i<=n; ++i) {
        cout << components[i] << " ";
    }
    cout << "\n";
}
