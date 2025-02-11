#include <bits/stdc++.h>
using namespace std;
const int mxX=300, mxN=1e3+1;
int t, x, p[mxX], v[mxN], dp[mxN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int g;
	cin >> g;
	for (int tt=1; tt<=g; ++tt) {
		cout << "Galho " << tt << ":\n";
		memset(dp, 0, sizeof(dp));
		cin >> t >> x;
		for (int i=0; i<t; ++i)
			cin >> v[i] >> p[i];
		for (int i=0; i<t; ++i)
			for (int j=x; j>=p[i]; --j)
				dp[j] = max(dp[j], dp[j-p[i]]+v[i]);
		cout << "Numero total de enfeites: " << dp[x] << "\n\n";	
	}
}
