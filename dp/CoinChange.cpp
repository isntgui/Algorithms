#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
      cin >> a[i];
    vector<int> dp(m+1, 1e7);
    dp[0] = 0;
    for(int i=0; i<n; ++i)
      for(int j=a[i]; j<=m; ++j)
        dp[j] = min(dp[j], dp[j-a[i]]+1);
    cout << dp[m] << "\n";
  }
}
