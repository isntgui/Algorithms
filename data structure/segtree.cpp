#include <bits/stdc++.h>
using namespace std;

const int mxN=400;

vector<int> a;
int tree[4*mxN];

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
	if(i<l||r<i) return;
	if(l==r) {
		tree[node] = x;
		return;
	}
	int m=(l+r)/2;
	update(2*node, l, m, i, x);
	update(2*node+1, m+1, r, i, x);
	tree[node] = tree[2*node] + tree[2*node+1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	a = { 0, 1, 3, 5, -2, 3 };
	int n = a.size();
	build(1, 0, n-1);
	cout << "Sum of values in range 0-4 are: " << query(1, 0, n - 1, 0, 4) << "\n";
	update(1, 0, n - 1, 1, 100);
	cout << "sum of value in range 1-3 are: " << query(1, 0, n - 1, 1, 3) << "\n";
}
