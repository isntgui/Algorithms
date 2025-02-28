
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN=400;

int tree[4*mxN], n, a[mxN];

int build(int node, int l, int r) {
	if(l==r) return tree[node] = a[l];
	int m = (l+r)/2;
	return tree[node] = build(2*node, l, m) + build(2*node+1, m+1, r);
}

int query(int node, int l, int r, int a, int b) {
	if(b<l||r<a) return 0;
	if(a<=l&&r<=b) return tree[node];
	int m = (l+r)/2;
	return query(2*node, l, m, a, b) + query(2*node+1, m+1, r, a, b);
}

void update(int node, int l, int r, int i, int x) {
	if(x<l||r<i) return;
	if(l==r) {
		tree[node] = x;
		return;
	}
	int m=(l+r)/2;
	update(2*node, l, m, i, x);
	update(2*node+1, m+1, r, i, x);
	tree[node] = tree[2*node] + tree[2*node+1];
}

int bs_st(int node, int l, int r, int k) {
    int s=0, p=0;
    for(int i=30; i>=0; --i) {
        if(p+(1<<i) <= n && s+query(1, 1, n, p+1, p+(1<<i)) <= k)
            s+=query(1, 1, n, p+1, p+(1<<i)), p+=(1<<i);
    }
    return p;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ;
}
