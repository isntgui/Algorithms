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

// Busca Binaria na estrutura de dados bit
int bs_bit(int v) {
    int s=0, p=0;
    for(int i=30; i>=0; --i) {
            if (p + (1 << i) <= n && s + ft[p + (1 << i)] <= v) {
                s += ft[p + (1 << i)];
                p += (1 << i);
}
    }
    return p;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ;
}
