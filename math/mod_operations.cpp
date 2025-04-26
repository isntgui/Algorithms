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

int exp(int base, long long exp) {
    int res = 1;
    while(exp){
        if(exp&1LL) 
            res = (res*1LL*base)%M;
        base = (base*1LL*base)%M;
        exp >>=1;
    }
    return res;
}

int invAdd(int a) {
    return mul(a, M-1);
}

int invMult(int a){
    return exp(a, M-2);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cout << add(5, 3) << "\n";
    cout << mul(10, 8) << "\n";
    cout << sub(90, 10) << "\n";
    cout << exp(3, 7) << "\n";
    cout << invAdd(10) << "\n";
    cout << invMult(10) << "\n";
}
