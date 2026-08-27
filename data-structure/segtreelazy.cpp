#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    vector<int> st, lz, a;
	const int NEUTRAL_ELEMENT = 0;
    int n;

    SegmentTree(vector<int>& v) : n((int)v.size()), a(v) {
        st.assign(4 * (n + 1) + 5, 0);
		lz.assign(4 * (n + 1) + 5, 0);
        build(1, 1, n);
    }

    int merge(int a, int b) {
        return a + b;
    }

	void unlazy(int node, int l, int r) {
		if (lz[node] == 0)
			return ;
		st[node] += (r - l + 1) * lz[node];
		if (l != r) {
			lz[2 * node] = lz[node];
			lz[2 * node + 1] = lz[node];
		}
		lz[node] = 0;
	}

    void build(int node, int l, int r) {
        if (l == r) {
            st[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        st[node] = merge(st[2 * node], st[2 * node + 1]);
    }

    void update(int node, int l, int r, int i, int j, int val) {
		unlazy(node, l, r);
        if (r < i || l > j)
            return;
		if (i <= l && r <= j) {
			lz[node] += val;
			unlazy(node, l, r);
			return ;
		}
        int mid = (l + r) / 2;
		update(2 * node, l, mid, i, j, val);
		update(2 * node + 1, mid + 1, r, i, j, val);
        st[node] = merge(st[2 * node], st[2 * node + 1]);
    }

    int query(int node, int l, int r, int i, int j) {
		if (j < l || i > r)
            return NEUTRAL_ELEMENT;
		unlazy(node, l, r);
        if (i <= l && j >= r)
            return st[node];
        int mid = (l + r) / 2;
        return merge(query(2 * node, l, mid, i, j), query(2 * node + 1, mid + 1, r, i, j));
    }

    void update(int a, int b, int v) {
        update(1, 1, n, a, b, v);
    }

    int query(int a, int b) {
        return query(1, 1, n, a, b);
    }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	;
}
