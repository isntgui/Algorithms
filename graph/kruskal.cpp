#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5 + 10;

int n, m;
int pai[mxn], sz[mxn];
vector<tuple<int, int, int>> edges;

void init() {
    for (int i = 1; i <= n; i++) {
        pai[i] = i;
        sz[i] = 1;
    }
}

int find(int u) {
    return pai[u] == u ? u : pai[u] = find(pai[u]);
}

bool unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return false;

    if (sz[u] < sz[v])
        swap(u, v);

    pai[v] = u;
    sz[u] += sz[v];

    return true;
}

long long kruskal() {
    sort(edges.begin(), edges.end());

    init();

    long long ans = 0;
    int cnt = 0;

    for (auto [u, v, w] : edges) {
        if (unite(u, v)) {
            ans += w;
            cnt++;
        }
    }

    if (cnt != n - 1)
        return -1;

    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}