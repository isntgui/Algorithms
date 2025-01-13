#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Bit {
    int n;
    vector<ll> bit;
    Bit(int _n=0) : n(_n), bit(n+1) {}

    void update(int i, ll x) {
        for(++i; i<=n; i+=i&-i) bit[i] += x;
    }

    ll qry(int i) {
        ll ret = 0;
        for(++i; i; i-=i&-i) ret += bit[i];
        return ret;
    }
};

void solve() {
    int n;
    cin >> n;
    Bit freq(n), par(n);
    ll ans = 0;
    for(int i=0, aux; i<n; ++i) {
        cin >> aux;
        aux = n - aux;
        ans += par.qry(aux-1);
        par.update(aux, freq.qry(aux-1));
        freq.update(aux, 1);
    }
    cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1;
	// cin >> t;
	while(t--)
		solve();
}
