#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

int lazy[4*mxN], st[4*mxN], a[mxN+1];

void bld(int node, int l, int r) {
    if(l==r) {
        st[node] = a[l];
        return;
    }
    int m = (l+r)/2;
    bld(2*node, l, m);
    bld(2*node+1, m+1, r);
    st[node] = max(st[2*node], st[2*node+1]);
}

void unlazy(int node, int l, int r) {
	if(lazy[node]==0) return ;
	st[node] = lazy[node];
	if(l!=r) {
		lazy[2*node] = lazy[node];
		lazy[2*node+1] = lazy[node];
	}
	lazy[node] = 0;
}

void upd(int node, int l, int r, int i, int j, int v) {
	unlazy(node, l, r);
	if(l>j||r<i) return;
	if(l>=i&&r<=j) {
		lazy[node] = v;
		unlazy(node, l, r);
		return;
	}
	int m = (l+r)/2;
	upd(2*node, l, m, i, j, v);
	upd(2*node+1, m+1, r, i, j, v);
	st[node] = max(st[2*node], st[2*node+1]);
}

int qry(int node, int l, int r, int a, int b) {
	unlazy(node, l, r);
	if(l>b||r<a) return 0;
	if(a<=l&&b>=r) return st[node];
	int m = (l+r)/2;
	return max(qry(2*node, l, m, a, b), qry(2*node+1, m+1, r, a, b));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for(int i=1; i<=10; ++i)
		a[i]=i;
	bld(1, 1, 10);
    cout << qry(1, 1, 10, 1, 3) << "\n";
}
