#include <bits/stdc++.h>
using namespace std;

// Código Tarjan

const int mxn = 2e5 + 5;

vector<int> adj[mxn];
vector<int> st;

int timer = 0, scc_cnt = 0;
int tin[mxn], low[mxn], comp[mxn];
bool in_stack[mxn];

void dfs(int u) {
    tin[u] = low[u] = timer++;

    st.push_back(u);
    in_stack[u] = true;

    for (int v : adj[u]) {
        if (tin[v] == -1) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }

    if (low[u] == tin[u]) {
        while (true) {
            int v = st.back();
            st.pop_back();

            in_stack[v] = false;
            comp[v] = scc_cnt;

            if (v == u)
                break;
        }

        scc_cnt++;
    }
}

void tarjan(int n) {
    fill(tin, tin + n, -1);

    for (int u = 0; u < n; u++)
        if (tin[u] == -1)
            dfs(u);
}

// Código Kosaraju

const int mxn = 2e5 + 5;

vector<int> adj[mxn], radj[mxn];
vector<int> order;

int comp[mxn];
bool vis[mxn];

void dfs1(int u) {
    vis[u] = true;

    for (int v : adj[u])
        if (!vis[v])
            dfs1(v);

    order.push_back(u);
}

void dfs2(int u, int id) {
    vis[u] = true;
    comp[u] = id;

    for (int v : radj[u])
        if (!vis[v])
            dfs2(v, id);
}

int kosaraju(int n) {
    order.clear();
    fill(vis, vis + n, false);

    for (int u = 0; u < n; u++)
        if (!vis[u])
            dfs1(u);

    fill(vis, vis + n, false);

    reverse(order.begin(), order.end());

    int scc_cnt = 0;

    for (int u : order) {
        if (!vis[u]) {
            dfs2(u, scc_cnt);
            scc_cnt++;
        }
    }

    return scc_cnt;
}