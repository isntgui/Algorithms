#include<bits/stdc++.h>
using namespace std;

const int mxn=1e5+10;

int n, q, st[4*mxn], a[mxn];

void bld(int node, int l, int r) {
    if(l==r) {
        st[node] = a[l];
        return ;
    }
    int mid = (l+r)/2;
    bld(2*node, l, mid);
    bld(2*node+1, mid+1, r);
    st[node] = st[2*node]+st[2*node+1];
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
    st[node] = st[2*node]+st[2*node+1];
}

int qry(int node, int l, int r, int i, int j) {
    if(i<=l&&j>=r)
        return st[node];
    if(j<l||i>r)
        return 0;
    int mid = (l+r)/2;
    return qry(2*node, l, mid, i, j)+qry(2*node+1, mid+1, r, i, j);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ;
}
