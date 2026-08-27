#include <bits/stdc++.h>
using namespace std;

#define int long long int

struct BIT {
    #define lsb(a) (a) & -(a)
    vector<int> ft;
    int len;

    BIT(int n) : len(n) {
        ft.resize(n + 1, 0);
    }

    BIT(vector<int> const& a) : BIT(a.size()) {
        for (int i = 0; i < (int)a.size(); i++)
            update(i, a[i]);
    }

    void update(int i, int v) {
        // i+1 para 1-based
        for (i++; i <= len; i += lsb(i))
            ft[i] += v;
    }

    int query(int i) {
        int ans = 0;
        for (i++; i; i -= lsb(i))
            ans += ft[i];
        return ans;
    }
};

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ;
}
