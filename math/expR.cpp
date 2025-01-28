#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll exp(int n, int k) {
	if(k==0) return 1;
	ll _k = exp(n, k/2);
	if(k%2==1) return _k*_k*n;
	return _k*_k;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cout << exp(5, 2) << "\n"; // 25
	cout << exp(5, 3) << "\n"; // 125
}