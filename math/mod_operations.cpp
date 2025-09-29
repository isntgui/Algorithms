#include<bits/stdc++.h>
using namespace std;

#define int int64_t

const int M=1e9+7; // 10⁹+7

int add(int a, int b) {
    return (a+b)%M;
}

int mul(int a, int b) {
    return 1ll*a*b%M;
}

int sub(int a, int b) {
    return (a-b+M)%M;
}

int exp(int base, long long e) {
    int res = 1;
    while(e){
        if(e&1LL) 
            res = (res*1LL*base)%M;
        base = (base*1LL*base)%M;
        e>>=1;
    }
    return res;
}

int invAdd(int a) {
    return (M - a) % M;
}

int invMult(int a){
    return exp(a, M-2);
}

int egcd(int a, int b, int &x, int &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    int x1, y1;
    int g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int invMultGeneral(int a, int m) {
    int x, y;
    int g = egcd(a, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}

int remainder(string num, int base, int mod) {
    int resp = 0;
    for(int i=0; i<(int)num.size(); i++)
        resp = ((num[i]-'0') + resp * base) % mod;
    return resp;
}

vector<int> fact, invfact;

void initFact(int n) {
    fact.resize(n+1);
    invfact.resize(n+1);
    fact[0] = 1;
    for(int i=1; i<=n; i++) fact[i] = mul(fact[i-1], i);
    invfact[n] = invMult(fact[n]);
    for(int i=n-1; i>=0; i--) invfact[i] = mul(invfact[i+1], i+1);
}

int nCr(int n, int r) {
    if(r < 0 || r > n) return 0;
    return mul(fact[n], mul(invfact[r], invfact[n-r]));
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //  ================================== Examples ==================================
    cout << add(5, 3) << "\n";
    cout << mul(10, 8) << "\n";
    cout << sub(90, 10) << "\n";
    cout << exp(3, 7) << "\n";
    cout << invAdd(10) << "\n";
    cout << invMult(10) << "\n";
    cout << remainder("10", 10, 4) << "\n";
    cout << invMultGeneral(7, 11) << "\n";
    initFact(10);
    cout << nCr(10, 3) << "\n";
}
