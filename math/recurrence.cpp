#include<bits/stdc++.h>
using namespace std;

// N-th number Fibonacci with recurrence liner O(N)
// binary exponentiation O(log N)
// time complexity O(log N)

#define int int64_t
#define mat vector<vector<int>>
#define sz(a) (int)a.size()

const int mxA=2e6, M=1e9+7, M2 = (int)M*M;

mat cn(int n, int m) {
    return vector<vector<int>>(n, vector<int>(m));
}

mat mult(mat &a, mat &b) {
    mat ret = cn(sz(a), sz(b[0]));
    for(int i=0; i<sz(a); ++i) {
        for(int k=0; k<sz(b); ++k) {
            for(int j=0; j<sz(b[0]); ++j) {
                ret[i][j]+=a[i][k]*b[k][j];
                ret[i][j]%=M;
            }
        }
    }
    return ret;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    mat ans = {{0, 1}};
    mat b = {{0, 1}, {1, 1}};
    while(n) {
        if(n&1)
            ans = mult(ans, b);
        b = mult(b, b);
        n/=2;
    }
    cout << ans[0][0] << "\n";
}
