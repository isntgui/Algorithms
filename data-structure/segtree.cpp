#include<bits/stdc++.h>
using namespace std;

const int mxn=1e5+10;

int n, q, st[4*mxn], a[mxn];

int func(int a, int b) {
    return a+b;
    // return max(a, b), min(a, b);
}

void bld(int node, int l, int r) {
    if(l==r) {
        st[node] = a[l];
        return ;
    }
    int mid = (l+r)/2;
    bld(2*node, l, mid);
    bld(2*node+1, mid+1, r);
    st[node] = func(st[2*node], st[2*node+1]);
}

void upd(int node, int l, int r, int i, int v) {
    if(l==r) {
        st[node] = v;
        return ;
    }
    int mid = (l+r)/2;
    if(i<=mid)
        upd(2*node, l, mid, i, v);
    else
        upd(2*node+1, mid+1, r, i, v);
    st[node] = func(st[2*node], st[2*node+1]);
}

int qry(int node, int l, int r, int i, int j) {
    if(i<=l&&j>=r)
        return st[node];
    if(j<l||i>r)
        return 0;
    int mid = (l+r)/2;
    return func(qry(2*node, l, mid, i, j), qry(2*node+1, mid+1, r, i, j));
}

int bs_seg(int node, int l, int r, int k) {
    if (st[node] < k) return -1;
    if (l == r) return l;
    int m = (l + r) / 2;
    if (st[2*node] >= k)
        return bs_seg(2*node, l, m, k);
    else
        return bs_seg(2*node+1, m+1, r, k - st[2*node]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ;
}
