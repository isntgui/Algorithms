#include <bits/stdc++.h>
using namespace std;

#define int long long
#define lsb(a) (a)&-(a)

const int mxn=1e5+10;

int a[mxn], ft[mxn], n, q, r, l;

void upd(int i, int v) {
    // i+1 caso o vetor seja indexado em 0, caso contrario não precisa
    for(++i; i<=n; i+=lsb(i))
        ft[i]+=v;
}

int qry(int i) {
    int ret = 0;
    for(++i; i; i-=lsb(i))
        ret+=ft[i];
    return ret;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    for(int i=0; i<n; ++i)
        cin >> a[i], upd(i, a[i]);
    while(q--) {
        cin >> r >> l;
        cout << qry(r)-qry(l-1) << "\n";
    }
}
