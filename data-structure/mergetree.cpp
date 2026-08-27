#include <bits/stdc++.h>
using namespace std;

struct MergeTree {
    int size;
    vector<vector<int>> ST;
    
    MergeTree(vector<int>& arr) {
        int N = arr.size()-1;
        size = N;
        ST.resize(4*N);
        build(1, 1, N, arr);
    }

    vector<int> join(vector<int> a, vector<int> b) {
        vector<int> resp;
        merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(resp));
        return resp;
    }

    void build(int node, int l, int r, vector<int>& arr) {
        if(l==r) {
            ST[node].push_back(arr[l]);
            return ;
        }
        int mid = (l+r)/2;
        build(2*node, l, mid, arr);
        build(2*node+1, mid+1, r, arr);
        ST[node] = join(ST[2*node], ST[2*node+1]);
    }

    vector<int> query(int node, int l, int r, int i, int j) {
        if(l>j||i>r) return {};
        if(i<=l&&j>=r) return ST[node];
        int mid = (l+r)/2;
        return join(query(2*node, l, mid, i, j), query(2*node+1, mid+1, r, i, j));
    }

    vector<int> query(int i, int j) {
        return query(1, 1, size, i, j);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
