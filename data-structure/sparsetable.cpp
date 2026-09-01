#include <bits/stdc++.h>
using namespace std;

#define int long long

struct SparseTable {
    vector<vector<int>> st;
    vector<int> lg;
    int n;

    SparseTable(const vector<int>& a) : n((int)a.size()) {
        int K = __lg(n) + 1;

        st.assign(K, vector<int>(n));
        lg.resize(n + 1);

        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        for (int i = 0; i < n; i++)
            st[0][i] = a[i];

        for (int k = 1; k < K; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                st[k][i] = merge(
                    st[k - 1][i],
                    st[k - 1][i + (1 << (k - 1))]
                );
            }
        }
    }

    int merge(int a, int b) {
        return min(a, b);
    }

    int query_RMQ(int l, int r) {
        int k = lg[r - l + 1];

        return merge(
            st[k][l],
            st[k][r - (1 << k) + 1]
        );
    }

    // int query_RSQ(int l, int r) {
    //     int ans = 0;

    //     for (int k = __lg(r - l + 1); k >= 0; k--) {
    //         if ((1 << k) <= r - l + 1) {
    //             ans += st[k][l];
    //             l += 1 << k;
    //         }
    //     }

    //     return ans;
    // }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
}
