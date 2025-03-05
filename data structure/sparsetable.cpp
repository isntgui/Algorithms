#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxn = 1e4 + 10, mxl = 31;

int sp[mxn][mxl], a[mxn], n, q;

void bld() {
    for(int i = 1; i <= n; ++i)
        sp[i][0] = a[i];
    for(int j = 1; j < mxl; ++j) {
        for(int i = 1; i <= n; ++i) {
            if(i + (1 << j) - 1 > n) break;
            sp[i][j] = sp[i][j-1] + sp[i + (1 << (j-1))][j-1];
            // sp[i][j] = min(sp[i][j-1], sp[i + (1 << (j-1))][j-1]);
        }
    }
}

int log_n(int x) {
    return 63 - __builtin_clzll(x);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
    cin >> a[i];
    bld();
    while(q--) {
        int l, r;
        cin >> l >> r;
        int k = log_n(r - l + 1);
        int ans = 0;
        for(int i=k; i>=0; --i) {
            if((1<<i) <= (r-l+1))
                ans+=sp[l][i], l+=(1<<i);
        }
        // cout << min(sp[l][k], sp[r-(1<<k)+1][k]) << "\n";
        cout << ans << "\n";
    }
}
