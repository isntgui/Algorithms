#include <bits/stdc++.h>
using namespace std;

const int mxn = 505;
const long long INF = 4e18;

int n, m;
long long dist[mxn][mxn];

void floyd_warshall() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                if(dist[i][k] == INF || dist[k][j] == INF)
                    continue;
                
                dist[i][j] = min(
                    dist[i][j],
                    dist[i][k] + dist[k][j]
                );
            }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ;
}