#include<bits/stdc++.h>
using namespace std;

struct SegmentTree {
    vector<int> st, a;
    int n, NEUTRAL_ELEMENT = 0;

    SegmentTree(vector<int>& v) : n((int)v.size()), a(v) {
        st.assign(4 * (n + 1) + 5, 0);
        build(1, 1, n);
    }

    int merge(int a, int b) {
        return a + b;
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

    void update(int node, int l, int r, int i, int j) {
        if (r < i || l > j)
            return;
        int mid = (l + r) / 2;
        if (i <= mid)
            update(2 * node, l, mid, i, j);
        else
            update(2 * node + 1, mid + 1, r, i, j);
        st[node] = merge(st[2 * node], st[2 * node + 1]);
    }

    int query(int node, int l, int r, int i, int j) {
        if (i <= l && j >= r)
            return st[node];
        if (j < l || i > r)
            return NEUTRAL_ELEMENT;
        int mid = (l + r) / 2;
        return merge(query(2 * node, l, mid, i, j), query(2 * node + 1, mid + 1, r, i, j));
    }

    void update(int a, int b) {
        update(1, 1, n, a, b);
    }

    int query(int a, int b) {
        return query(1, 1, n, a, b);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ;
}