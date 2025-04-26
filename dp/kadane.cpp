#include <bits/stdc++.h>
using namespace std;
	
int kadane(vector<int> v) {
	int mu = 0, ml = 0;
	for (auto i : v) {
		ml += i;
		if (ml > mu)
			mu = ml;
		if (ml < 0)
			ml = 0;
	}
	return mu;
}
	
int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	;
}
