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

/*
Obs: Quando o valor é muito alto, pode ser possível utilizar um dp 'inversa', como a dp é pelo máximo de valor, essa dp calcula 
o mínimo de peso para fazer a soma, isso funcionando quando W >= Soma_dos_valores
	
#include <bits/stdc++.h>
using namespace std;

#if __has_include("debugging.h")
#include "debugging.h"
#endif

#define int long long int

#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define fr first
#define sc second

constexpr int INF = 1e18 + 10;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w;
    cin >> n >> w;
    vector<int> a(n), b(n);
    int soma = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i], soma += b[i];
    vector<int> dp(soma + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = soma; j >= b[i]; j--) {
            dp[j] = min(dp[j], dp[j - b[i]] + a[i]);
        }
    }
    for (int i = soma; i >= 0; i--) {
        if (dp[i] <= w) {
            cout << i << "\n";
            return 0;
        }
    }
}

*/
