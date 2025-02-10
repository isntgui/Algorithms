#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define F first
#define S second
#define dbg(x) cout << x << "\n";
#define ar array
#define sz(a) ((int)a.size())

double solve() {
	vt<ar<int, 2>> fig(5, ar<int, 2>());
	int s1=0, s2=0;
	for(int i=0; i<4; ++i) {
		cin >> fig[i][0] >> fig[i][1];
	}
	fig[4][0] = fig[0][0], fig[4][1] = fig[0][1];
	for(int i=0; i<5; ++i)
		s1+=(fig[i][0]*fig[i+1][1]);
	for(int i=0; i<5; ++i) {
		if(i==4) continue;
		s2+=(fig[i][1]*fig[i+1][0]);
	}
	return (double)0.5*abs(s1-s2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	double a1 = solve();
	double a2 = solve();
	char ans='A';
	if(a2>a1)
		ans='B';
	cout << "terreno " << ans << "\n";
} 
