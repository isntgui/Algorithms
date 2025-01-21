#include<bits/stdc++.h>
using namespace std;

const int mxn=100, mxX=650;
int n, t, p[mxn], v[mxn], dp[mxX], ind=0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (cin >> n >> t && n) {
		cout << "Instancia " << ++ind << "\n";
		memset(dp, 0, sizeof(dp));
		for (int i=0; i<n; ++i) {
			cin >> p[i] >> v[i];
		}
		for (int i=0; i<=t; ++i) {
			for (int j=0; j<=n; ++j) {
				if (p[j] <= i) 
					dp[i] = max(dp[i], dp[i-p[j]] + v[j]);
			}
		}
		cout << dp[t] << "\n\n";
	}
}
