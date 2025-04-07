#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int mxn = 25, mxm = (1<<15)+10;
const int INF = LLONG_MAX;

int n, m;
int adj[mxn][mxn], dp[mxm][mxn];

int tsp(int mask, int i) {
    if(mask == (1 << n) - 1)
        return adj[i][0] == 0 ? INF : adj[i][0];
    if(dp[mask][i] != -1) return dp[mask][i];
    int ans = INF;
    for(int v = 0; v < n; ++v) {
        if(mask & (1 << v) || !adj[i][v]) continue;
        ans = min(ans, tsp(mask | (1 << v), v) + adj[i][v]);
    }
    return dp[mask][i] = ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c, --a, --b;
        adj[a][b] = adj[b][a] = c;
    }

    memset(dp, -1, sizeof(dp));
    cout << tsp(1, 0) << "\n";
}
