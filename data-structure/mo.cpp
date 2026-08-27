#include <bits/stdc++.h>
using namespace std;

// Mo's algorithm, O((N + Q) * sqrt(N))
// queries offline

constexpr int mxn = 1e5+10;

int n, q;
int arr[mxn];
long long ans[mxn];
long long currSum;
int block;

struct Query {
    int left, right, index;

    bool operator<(const Query& other) const {
        if(left / block != other.left / block)
            return left / block < other.left / block;
        return right < other.right;
    }
};

void add(int x) {
    currSum += x;
}

void remove(int x) {
    currSum -= x;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    block = sqrt(n);
    vector<Query> qry(q);
    for(int i=0; i<q; i++) {
        cin >> qry[i].left >> qry[i].right; // 1-based
        qry[i].index = i;
    }
    sort(qry.begin(), qry.end());
    int currL = 1, currR = 0;
    currSum = 0;
    for(auto q : qry) {
        while(currL > q.left)
            add(arr[--currL]);
        while(currR < q.right)
            add(arr[++currR]);
        while(currL < q.left)
            remove(arr[currL++]);
        while(currR > q.right)
            remove(arr[currR--]);
        ans[q.index] = currSum;
    }
    for(int i=0; i<q; i++)
        cout << ans[i] << "\n";
}
