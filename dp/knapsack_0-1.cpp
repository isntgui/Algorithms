#include<bits/stdc++.h>
using namespace std;

const int mxn=100, mxX=650;
int n, w, p[mxn], v[mxn], dp[mxX], ind=0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> w;
	for(int i=0; i<n; ++i)
		cin >> p[i] >> v[i];
	for(int i=0; i<n; ++i)
		for(int j=w; j>=p[i]; --j)
			dp[j] = max(dp[j], dp[j-p[i]]+v[i]);
	cout << dp[w] << "\n";
}
