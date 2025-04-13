#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int rem(int a, int b) {
    return (b+(a%b))%b;
}

int inv_mod(int a, int b) {
    int os=1, s=0;
    int ot=0, t=1;
    while(a%b!=0) {
        auto dr = div(a, b);
        os = exchange(s, os-dr.quot*s);
        ot = exchange(t, ot-dr.quot*t);
        a = exchange(b, dr.rem);
    }
    return s;
}

int crt(vector<int> a, vector<int> m) {
    int n = a.size();
    int M = 1;
    for(int i=0; i<n; ++i)
        M*=m[i];
    int ret = 0;
    for(int i=0; i<n; ++i) {
        int mi = M/m[i];
        int yi = inv_mod(mi, m[i]);
        ret+=a[i]*mi*yi;
    }
    ret = rem(ret, M);
    return (ret==0?M:ret);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ;
}
