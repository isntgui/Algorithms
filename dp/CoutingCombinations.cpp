#include<bits/stdc++.h>
using namespace std;

const int M=1e9+7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n;
  cin >> n;
  vector<int> dp(n+1, 0);
  dp[0]=1;
  for(int i=0; i<n; ++i)
    for(int j=1;  j<=n; ++j)
      dp[i+j] = (dp[i+j]+dp[i])%M;
  cout << dp[n] << "\n";
}
