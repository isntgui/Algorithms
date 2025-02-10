#include<bits/stdc++.h>
using namespace std;

const int mxn=110;

int a[mxn][mxn], dp[mxn][mxn], n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cin >> a[i][j];
    
    dp[0][0] = a[0][0]; //casos base
    for(int i=1; i<n; ++i)
        dp[i][0] = dp[i-1][0]+a[i][0];
    for(int i=0; i<m; ++i)
        dp[0][i] = dp[0][i-1]+a[0][i];
    
    for(int i=1; i<n; ++i)
        for(int j=1; j<m; ++j)
            dp[i][j] = min(dp[i-1][j]+a[i][j],
                dp[i][j-1]+a[i][j]); // é melhor pegar o de cima ou da esquerda?
    cout << dp[n-1][m-1] << "\n"; // imprime o menor caminho até ultimo elemento
}
